%{
int yylex();
int yyerror(char*);
#include <stdio.h>
#include <string.h>
#include "linkedlist.c"
#include "bintree.c"
#include "record.c"
#include "PatchList.c"
extern int lineno;
extern int instr;
extern int curr_reg;
extern int curr_var;
int proc_size[999];
int proc_i = 0; 
int next_exception = 3;
bool in_exception_part = false; 
int jump_table[999];
%}

%token IS BEG END PROCEDURE ID NUMBER TYPE ARRAY RAISE OTHERS
%token RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION NULLWORD LOOP IF
%token THEN ELSEIF ELSE EXIT WHEN AND OR EQ NEQ LT GT GTE LTE TICK
%token NOT EXP ARROW OF DOTDOT ENDIF ENDREC ENDLOOP EXITWHEN ACCESS NEW DOTALL
%type <integer> NUMBER constant_num procedure_begin loop_start exception_list exception_hand exception_part
%type <var> ID type_name mode procedure_specification adding_operation multiplying_operation boolean_operation relational_operation choice_sequence
%type <head> identifier_list
%type <b_node> formal_parameter_part parameters
%type <c_record> primary factor term simple_expression relation expression opt_actual_para_part expression_list condition opt_assign
%union {
    int integer;
    char *var;
    struct LL_node* head;
    struct binary_tree_node* b_node;
    struct address_record* c_record;
}
%%

program                 : main_body {
									printf ("\n*******\nDONE.\n*******\n"); 

									pop();
									FILE * outcode;
							        outcode = fopen("./sample.out", "w");
									for (int i =0; i < instr; i++) {
                                        char snum[5];
                                        sprintf(snum, "%d: ", i);
                                        fprintf(outcode, snum);
                                        char *patcher = (char*)malloc(8 * sizeof(char));
                                        patcher = strstr(output[i], "?");
                                        if (patcher != NULL) {
                                            int content = search_PL(Patch_list, i);
                                            printf("line %d: patch %d\n", i, content);
                                            //sprintf(patcher, "%d", );
                                        }
							        	fprintf(outcode, output[i]);
                                        fflush(outcode);
							    	}

							     	 }
                        ;
main_body               : main_specification IS
                          declarative_part main_beg
                          sequence_of_statements
                          exception_part END ';'  {
                            patch_jump_ex(Patch_list, -3, instr);
                            if ($6 == 0){
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
                          	}
                          	printf("\nPoping scope for %s, so print tree\n", stack_b[count].name); present(stack_b[count-1].root); 
                          							char *temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "RETURN: r%d := contents b, 1\n", curr_reg);
													output[instr++] = temp;
													temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "b := contents b, 3\n");
													output[instr++] = temp;
													temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "pc = r%d\n", curr_reg++);
													output[instr++] = temp;
                                                    add_rear_PL(0, instr);
                                                    add_rear_PL(1, instr+4+proc_size[0]);
                                                    //print_PL(Patch_list);
                          							pop(); }
                        ;
main_beg                : BEG
                        {add_rear_PL(4, instr);
                        print_PL(Patch_list);
                        push_PL_ex();}
                        ;
main_specification      : PROCEDURE ID
                        {
                        output[instr++] = "b := ?\n"; 
						output[instr++] = "contents b, 0 := ?\n";
						output[instr++] = "contents b, 1 := 4\n";
						output[instr++] = "r1 = 0\n";
                        curr_reg++;
						output[instr++] = "pc := ?\n";
						output[instr++] = "halt\n";
                        push($2);
                        printf("\nPushing new scope for %s\n", stack_b[count].name);
                    	}
                        ;
procedure_body          : procedure_specification formal_parameter_part IS
                          declarative_part procedure_begin
                          sequence_of_statements
                          exception_part END ';' {
                            patch_jump_ex(Patch_list, -3, instr);
                            if ($7 == 0){
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
                            }
                          	int offset; 
    						node* curr_node = search_in_stack($1, &offset);
                            curr_node-> next = $2;
                            curr_node-> value = proc_size[proc_i];
                            printf("size of %s is %d", curr_node->symbol, curr_node->value);
                            curr_node->proc_begin = $5;
                            if (curr_node -> next != NULL) {
                            printf("next of %s is %s\n", curr_node->symbol, curr_node->next->symbol);
                            }
                            printf("\nPoping scope for %s, so print tree\n", stack_b[count].name);
                            present(stack_b[count-1].root);
                            char *temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "RETURN: r%d := contents b, 1\n", curr_reg);
							output[instr++] = temp;
							temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "b := contents b, 3\n");
							output[instr++] = temp;
							temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "pc = r%d\n", curr_reg++);
							output[instr++] = temp;
                            pop();
                            proc_size[proc_i] = 0;
                            proc_i--;

                        }
                        ;
procedure_begin			: BEG
						{push_PL_ex();
							$$ = instr;
						}
						;
procedure_specification : PROCEDURE ID 
                        {printf("line %d: procedure %s (...)\n", lineno, $2);
                        if(recursive_search_local(stack_b[count-1].root, $2) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add($2);
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack($2, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "procedure";
                                //curr_node->next = $3;
                                present(stack_b[count-1].root);
                                //printf("\n");
                            }
                        push($2);
                        printf("\nPushing new scope for %s\n", stack_b[count].name);
                        $$ = $2;
                        proc_i++;}
                        ;
formal_parameter_part   : '(' parameters ')'
						{$$ = $2;}
                        |
                        {$$ = NULL;}
                        ;
parameters              : identifier_list ':' mode type_name ';' parameters
                        {   printf("line %d:", lineno);
                            print($1); 
                            printf(": %s %s\n", $3, $4);
                            LL_node current;
                            current = $1;
                            node* curr_node;
                            node* previous;
                            node* first;
                            int counter = 0;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}

                                add(current->data);
                                //printf("ADD %s into the tree %s.\n", current->data, stack_b[count].name);
                                int offset;
                                curr_node = search_in_stack(current->data, &offset);
                                if (counter == 0) {
                                    first = curr_node;
                                }

                                curr_node = empty_node(curr_node);
                                curr_node->kind = "parameters";
                                curr_node->mode = $3;
                                curr_node->parent_type = search_in_stack($4, &offset);
                                if (counter > 0) {
                                    previous->next = curr_node;
                                    printf("next of %s is %s\n", previous->symbol, previous->next->symbol);
                                }
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                previous = curr_node;
                                current = current -> next;
                                counter++;
                          }

                          curr_node->next = $6;
                          printf("next of %s is %s\n", curr_node->symbol, curr_node->next->symbol);
                          $$ = first;
                        }
                        | identifier_list ':' mode type_name
                        {   printf("line %d:", lineno);
                            print($1); 
                            printf(": %s %s\n", $3, $4);
                            LL_node current; 
                            node* curr_node;
                            node* previous;
                            node* first;
                            current = $1;
                            int counter = 0;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                //printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                curr_node = search_in_stack(current->data, &offset);
                                if (counter == 0) {
                                    first = curr_node;
                                }
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "parameters";
                                curr_node->mode = $3;
                                curr_node->parent_type = search_in_stack($4, &offset);
                                if (counter > 0) {
                                    previous->next = curr_node;
                                    printf("next of %s is %s\n", previous->symbol, previous->next->symbol);
                                }
                                //present(stack_b[count-1].root);
                                previous = curr_node;
                                current = current -> next;
                                counter++;
                          }
                          $$ = first;
                              
                        }
                        ;
mode                    : IN OUT
						{$$ = "in out";}
                        | OUT
                        {$$ = "out";}
                        | IN
						{$$ = "in";}
                        |
						{$$ = "";}
                        ;
type_name               : ID    {$$ = $1;}
                        ;
declarative_part        : objects ';' declarative_part
                        | types ';' declarative_part
                        | exceptions ';' declarative_part
                        | declarative_part_p
                        ; 
declarative_part_p      : procedure_body declarative_part_p
                        | 
                        ;
types                   : TYPE ID IS ARRAY  '(' constant_num DOTDOT constant_num ')' OF type_name
                        {   printf("line %d: type %s is array (%d..%d) of %s\n", lineno, $2, $6, $8, $11);
                            if(recursive_search_local(stack_b[count-1].root, $2) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add($2);
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack($2, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "type (array)";
                                curr_node->component_type = search_in_stack($11, &offset);
                                curr_node->upper = $8;
                                curr_node->lower = $6;
                                curr_node->value = ($8-$6+1) * curr_node->component_type->value;
                                //present(stack_b[count-1].root);
                                //printf("\n");
                            }
                              
                        }
                        | TYPE ID IS RECORD component_list ENDREC
                        | TYPE ID IS RANGE constant_num DOTDOT constant_num
                        {   printf("line %d: type %s is range %d..%d\n", lineno, $2, $5, $7);
                            if(recursive_search_local(stack_b[count-1].root, $2) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add($2);
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack($2, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "type (range)";
                                curr_node->upper = $7;
                                curr_node->lower = $5;
                                //present(stack_b[count-1].root);
                                //printf("\n");
                            }
                              
                        }
                        ;
constant_num			: NUMBER
						{$$ = $1;}
						| ID {$$ = 0;}
						;
component_list          : component ';' component_list
                        | component ';'
                        ;
component               : objects
                        ;
objects                 : identifier_list ':' type_name
                        {   printf("line %d:", lineno);
                            print($1); 
                            printf(": %s\n", $3);
                            LL_node current; 
                            current = $1;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                node* curr_node = search_in_stack(current->data, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "variable";
                                curr_node->parent_type = search_in_stack($3, &offset);
                                if (strcmp(curr_node->parent_type->kind, "type (array)") == 0){
                                
                                curr_node->value = 4 + proc_size[proc_i];
                                proc_size[proc_i] = proc_size[proc_i] + curr_node->parent_type->value;                                
                                printf("in array value is %d\n", curr_node->parent_type->value);
                                } else {
                                
                                curr_node->value = 4 + proc_size[proc_i];
                                proc_size[proc_i] = proc_size[proc_i] + curr_node->parent_type->value; 
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                }
                                current = current -> next;
                          }
                        }
                        | constant
                        ;
constant                : identifier_list ':' CONSTANT ASSIGN constant_expression
                        ;
constant_expression     : expression
                        ;
exceptions              : identifier_list ':' EXCEPTION
                        {   printf("line %d:", lineno);
                            print($1); 
                            printf(":exception\n");
                            LL_node current; 
                            current = $1;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                node* curr_node = search_in_stack(current->data, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "exception";
                                curr_node->value = next_exception;
                                next_exception++;
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                current = current -> next;
                          }
                        }
                        ;
sequence_of_statements  : statement sequence_of_statements
                        | 
                        ;


statement               : 
                        ID opt_actual_para_part opt_assign ';'
                        {int offset;
                        node* curr_node = search_in_stack($1, &offset);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        //search the stack for the ID type

                        //read routine
                        if (strcmp(curr_node->kind, "read_routine") == 0) {
                            if ($2 ->is_var){ 
                            sprintf(temp, "READ: read contents b, %d\n", $2->var_loc);
                            output[instr++] = temp;
                            }
                            else {sprintf(temp, "READ: read contents r%d, %d\n",$2->reg_number-1, $2->var_loc);
                            output[instr++] = temp;
                            }
                        } 


                        //write routine
                        else if (strcmp(curr_node->kind, "write_routine") == 0) { 
                            for (int i = 0; i < $2->curr_top; i++ ) {
                                temp = (char*)malloc(40 * sizeof(char));
                                sprintf(temp, "WRITE: write %s%d\n",($2->exp_list[i] < 0)? "contents b, ":"r", 
                                                                    ($2->exp_list[i] < 0)? $2->exp_list[i]*-1:$2->exp_list[i]);
                                output[instr++] = temp; 
                            }


                        //procedure call    
                        } else if (strcmp(curr_node->kind, "procedure") == 0) {
                            
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "FUNCTION CALL: r%d := b\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "b := contents r%d, 0\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 3 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            int offset = 0;
                            search_in_stack(curr_node->symbol, &offset);
                            //printf("FUNCTION CALL: offset is %d\n",offset);
                            if (offset == 0) {
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 2 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            }else {
                            for (int i = 0; i < offset; i++){
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                            output[instr++] = temp;
                            }
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 2 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            }
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := %d\n", ++curr_reg, 4 + curr_node->value);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 0 := b + r%d\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := ", ++curr_reg);
                            int patch_return = instr;
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 1 := r%d\n", curr_reg++);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "JUMP: pc := %d\n", curr_node->proc_begin);
                            output[instr++] = temp;
                            sprintf(output[patch_return], "%s%d\n", output[patch_return], instr);
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "pc := ? if r1\n");
                            output[instr++] = temp;
                            add_PL_ex(instr-1, -7);
                        
                    }


                        //variables 
                        else if (strcmp(curr_node->kind, "variable") == 0 && strcmp(curr_node->parent_type->kind, "integer")==0) {
                            temp = (char*)malloc(100 * sizeof(char));
                            if (offset == 0) {
                            
                            sprintf(temp, "ASSIGNMENTS: contents b, %d := %s%d\n", curr_node->value,
                                                                    $3->is_var? "contents b, ":"r", 
                                                                    $3->is_var?$3->var_loc:$3->reg_number);
                            output[instr++] = temp;
                            } else {
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "NONLOCAL ASSIGNMENTS: r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                for (int i = 0; i<offset; i++){ 
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "contents r%d, %d := %s%d\n", curr_reg, curr_node->value,
                                                                    $3->is_var? "contents b, ":"r", 
                                                                    $3->is_var?$3->var_loc:$3->reg_number);
                                output[instr++] = temp;
                                curr_reg++;
                            }
                        }



                        //array
                        else if (strcmp(curr_node->kind, "variable") == 0 && strcmp(curr_node->parent_type->kind, "type (array)")==0) {
                            if (offset == 0) {
                            if ($2 -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, $2->var_loc);
                                    output[instr++] = temp;

                            }
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ASSIGNMENTS: contents b, r%d, %d := %s%d\n", curr_reg, curr_node->value,
                                                                    $3->is_var? "contents b, ":"r", 
                                                                    $3->is_var?$3->var_loc:$3->reg_number);
                            output[instr++] = temp;
                            curr_reg++;
                            } else {
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "NONLOCAL ASSIGNMENTS: r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                for (int i = 0; i<offset; i++){ 
                                    temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                int reg_for_wb = curr_reg;
                                curr_reg++;
                                if ($2 -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, $2->var_loc);
                                    output[instr++] = temp;

                                }
                                temp = (char*)malloc(100 * sizeof(char));   
                                sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                                output[instr++] = temp;
                                int reg_for_index = curr_reg;
                                curr_reg++;
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "contents r%d, r%d, %d := %s%d\n", reg_for_wb, reg_for_index, curr_node->value,
                                                                    $3->is_var? "contents b, ":"r", 
                                                                    $3->is_var?$3->var_loc:$3->reg_number);
                                output[instr++] = temp;
                            }
                        }
                        
                    }
                        | loop_part
                        | if_statement
                        | RAISE ID ';'
                        {
                        int offset;
                        node* curr_node = search_in_stack($2, &offset);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        if (curr_node != NULL && strcmp(curr_node -> kind, "exception") == 0) {
                        	printf("found exception\n");
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "r1 = %d\n", curr_node->value);
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;


                        }
                        add_PL_ex(instr-1, -7);
                        }
                        | RAISE ';'
                        {
                        	char *temp = (char*)malloc(40 * sizeof(char));
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                            add_rear_PL(instr-1, -3);
                        }
                        | NULLWORD';'
                        ;
opt_assign              : ASSIGN expression
                        {$$ = $2;}
                        |
                        {$$ = NULL;}
                        ;
opt_actual_para_part    :'(' expression_list ')'
                        {$$ = $2;}
                        |
                        {$$=NULL;}
                        ;
expression_list         : expression_list ',' expression
						{
                            if ($3->is_var) $1->exp_list[$1 -> curr_top++] = -1*$3 -> var_loc;

                            else $1->exp_list[$1 -> curr_top++] = $3 -> reg_number;
                            $$ = $1;
						}
                        | expression
                        {
                            if ($1->is_var) $1->exp_list[$1 -> curr_top++] = -1*$1 -> var_loc;

                            else $1->exp_list[$1 -> curr_top++] = $1 -> reg_number;
                            $$ = $1;
                        }
                        ;
                        //LOOP STATEMENTS
loop_part               : loop_start inside_loop ENDLOOP ';'
                        {
                        if (Patch_list == NULL)
                        {Patch_list = retrieve_PL();}
                        else
                        {toEnd_PL(Patch_list) -> next= retrieve_PL();}
                        pop_PL();
                        patch_jump(Patch_list, instr+1);
                        print_PL(Patch_list);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        sprintf(temp, "ENDLOOP: pc := %d\n", $1);
                        output[instr++] = temp;
                        }
                        ;
loop_start              : LOOP
                        {push_PL();
                        $$ = instr;}
                        ;
inside_loop             : loop_statements
                        | inside_loop loop_statements
                        ;
loop_statements         : statement
                        | exit_cond
                        ;
exit_cond               : EXITWHEN condition ';'
                        {   char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "COND EXIT: pc := ? if r%d\n", $2->reg_number);
                            output[instr++] = temp;
                            add_PL(instr-1, -7);
                        }
                        | EXIT ';'
                        {   char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "COND EXIT: pc := ?\n");
                            output[instr++] = temp;
                            add_PL(instr-1, -7);
                        }
                        ;
                        //END OF LOOP STATEMENTS
                        //IF STATEMENTS
if_statement            : ifcond sequence_of_statements else_if else endif ';'
						{
						if (Patch_list == NULL)
                        {Patch_list = retrieve_PL();}
                        else
                        {toEnd_PL(Patch_list) -> next= retrieve_PL();}
                        pop_PL();
                        printf("Patching IFs:\n");
                        patch_jump(Patch_list, instr);
                        print_PL(Patch_list);
						}

                        ;
ifcond                  : IF condition then_cond
						{	push_PL();
                            char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "IF COND: pc := ? if not r%d\n", $2->reg_number);
                            output[instr++] = temp;
                            add_PL(instr-1, -7);}
						;
else_if                 : ELSEIF condition then_cond sequence_of_statements else_if
                        | 
                        ;
then_cond               : THEN
                        ;
else                    : ELSE sequence_of_statements
                        | 
                        ;
endif 					: ENDIF
						;
condition               : expression
                        {$$ = $1;}
                        ;
                        //END OF IF STATEMENTS


expression              : relation
						{$$ = $1;
						}
						| expression boolean_operation relation 
						{struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "BOOLEAN: r%d := %s%d %s %s%d\n", curr_reg++, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number,
																	$2, 
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number);
							output[instr++] = temp;
							$$ = new_record;
						}
                        ;
relation                : simple_expression
						{$$ = $1;
						}
						| relation relational_operation simple_expression
						{struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
                            if ($1->is_var) {
                                temp = (char*)malloc(40 * sizeof(char));
                                $1-> reg_number = curr_reg;
                                $1-> is_var = false; 
                                sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, $1->var_loc);
                                output[instr++] = temp;
                            }
                            if ($3->is_var) {
                                temp = (char*)malloc(40 * sizeof(char));
                                $3-> reg_number = curr_reg;
                                $3-> is_var = false; 
                                sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, $3->var_loc);
                                output[instr++] = temp;
                            }
                            temp = (char*)malloc(100 * sizeof(char));
							if (strcmp($2, ">") == 0 ) {
							sprintf(temp, "r%d := %s%d < %s%d\n", curr_reg++, 
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							$$ = new_record;
							} else if (strcmp($2, ">=") == 0) {
								sprintf(temp, "r%d := %s%d <= %s%d\n", curr_reg++, 
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							$$ = new_record;
							}else {
							sprintf(temp, "r%d := %s%d %s %s%d\n", curr_reg++, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number,
																	$2, 
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							$$ = new_record;
							}
						}
                        ;
simple_expression       : '-' term
						{	struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NEGATIVE: r%d := -1 * %s%d\n", curr_reg++, 
																	$2->is_var? "contents b, ":"r", 
																	$2->is_var?$2->var_loc:$2->reg_number);
							output[instr++] = temp;
							$$ = new_record;}
						| term
						{$$ = $1;
						}
						| simple_expression adding_operation term
						{struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "ADD: r%d := %s%d %s %s%d\n", curr_reg++, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number, 
																	$2,
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number);
							output[instr++] = temp;
							$$ = new_record;}
                        ;
term                    : factor
						{$$ = $1;
						}
						| term multiplying_operation factor
						{	struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "MULTIPLY: r%d := %s%d %s %s%d\n", curr_reg++, 
																	$1->is_var? "contents b, ":"r", 
																	$1->is_var?$1->var_loc:$1->reg_number,
																	$2, 
																	$3->is_var? "contents b, ":"r", 
																	$3->is_var?$3->var_loc:$3->reg_number);
							output[instr++] = temp;
							$$ = new_record;
}
                        ;
factor              	: NOT primary
						{struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NEGATION: r%d := not %s%d\n", curr_reg++, 
																	$2->is_var? "contents b, ":"r", 
																	$2->is_var?$2->var_loc:$2->reg_number);
							output[instr++] = temp;
							$$ = new_record;}
						| primary EXP primary
						{$$ = $1;}
						| primary
						{$$ = $1;
						}
                        ;
primary                 : NUMBER
						{
							struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(40 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NUMBER: r%d := %d\n", curr_reg++, $1);
							output[instr++] = temp;
							$$ = new_record;

						}
                        | ID
                        {
                            struct address_record* new_record = create_new_record();
                            node * curr_node; 
							int offset = 0;
							curr_node = search_in_stack($1, &offset);
							//printf("offset is %d\n",offset);
							if (strcmp($1, "true") == 0 || strcmp($1, "false") == 0) {
								struct address_record* new_record = create_new_record(); 
								char *temp = (char*)malloc(40 * sizeof(char));
								new_record->reg_number = curr_reg;
								sprintf(temp, "r%d := %s\n", curr_reg++, $1);
								output[instr++] = temp;
								$$ = new_record;
							} else {
                            if (offset == 0) {
                                new_record -> var_loc = curr_node -> value;
                                char *temp = (char*)malloc(40 * sizeof(char));
								//new_record->reg_number = curr_reg;
								new_record-> is_var = true; 
								//sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, new_record->var_loc);
								//output[instr++] = temp;
								$$ = new_record;
                                
                            } else {
                               	char *temp = (char*)malloc(100 * sizeof(char));
								sprintf(temp, "r%d := b\n", curr_reg);
								output[instr++] = temp;
                                new_record -> var_loc = curr_node -> value;
								for (int i = 0; i<offset; i++){ 
									char *temp = (char*)malloc(100 * sizeof(char));
									sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
									output[instr++] = temp;
								}
								curr_reg++;
                                temp = (char*)malloc(100 * sizeof(char));
                                new_record->reg_number = curr_reg;
                                sprintf(temp, "r%d := contents r%d, %d\n", curr_reg++, curr_reg-1,new_record -> var_loc);
                                output[instr++] = temp;

                            }
                              $$ = new_record;
                          }

						}
                        | ID '('expression')'
                        {
                            struct address_record* new_record = create_new_record();
                            node * curr_node; 
                            int offset = 0;
                            curr_node = search_in_stack($1, &offset);
                            //printf("offset is %d\n",offset);
                            if (offset == 0) {
                            if ($3 -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, $3->var_loc);
                                    output[instr++] = temp;

                            }
                            char *temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                            curr_reg++;
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "r%d := contents b, r%d, %d\n", curr_reg, curr_reg-1, curr_node->value);                            
                            output[instr++] = temp;
                            new_record->reg_number = curr_reg;
                            curr_reg++;
                            $$ = new_record;
                                
                            } else {
                                char *temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                new_record -> var_loc = curr_node -> value;
                                for (int i = 0; i<offset; i++){ 
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                curr_reg++;
                                if ($3 -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, $3->var_loc);
                                    output[instr++] = temp;

                                }
                                temp = (char*)malloc(100 * sizeof(char));   
                                sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                                curr_reg++;
                                output[instr++] = temp;
                                temp = (char*)malloc(100 * sizeof(char));
                                new_record->reg_number = curr_reg;
                                sprintf(temp, "r%d := contents r%d, r%d, %d\n", curr_reg++, curr_reg-1, curr_reg -2, new_record -> var_loc);
                                output[instr++] = temp;

                            }
                              $$ = new_record;
                          }

                        | '(' expression ')'
                        {$$ = $2;}
                        ;
boolean_operation       : AND
						{$$ = "and";}
                        | OR
                        {$$ = "or";}
                        ;
relational_operation    : EQ
						{$$ = "=";}
                        | NEQ
                        {$$ = "/=";}
                        | LT
                        {$$ = "<";}
                        | GT
                        {$$ = ">";}
                        | GTE
                        {$$ = ">=";}
                        | LTE
                        {$$ = "<=";}
                        ;
adding_operation        : '+'
						{$$ = "+";}
                        | '-'
                        {$$ = "-";}
                        ;
multiplying_operation   : '*'
						{$$ = "*";}
                        | '/'
                        {$$ = "/";}
                        ;
exception_part          : exception_start exception_list
						{
                            patch_jump_ex(Patch_list, -4, instr-1);
				
                            for(int i = 1; i < next_exception; i++) {
                                if (jump_table[i] == 0)
                                jump_table[i] = instr+next_exception-1;
                            }
                            for(int i = 1; i < next_exception; i++){
                            char *temp = (char*)malloc(40 * sizeof(char));
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = %d\n", jump_table[i]);
                            output[instr++] = temp;
                            }
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
						}
                        |
                        {$$ = 0;} 
                        ;
exception_start         : EXCEPTION
						{
                            for (int i =1; i<next_exception;i++) {
                            jump_table[i] = 0;
                        }
                        	char *temp = (char*)malloc(40 * sizeof(char));
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = r1, ?\n");
                            output[instr++] = temp;
                            
                            if (Patch_list == NULL)
                        	{Patch_list = retrieve_PL_ex();}
                       		else
                        	{
                        	printf("Patching procedures:\n");
                        	toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                        	pop_PL_ex();
                        	patch_jump(Patch_list, instr-1);
                            
                        	print_PL(Patch_list);
                        	push_PL_ex();
                        	add_PL_ex(instr-2, -7);
                        	add_rear_PL(instr-1, -4);
                        }
                        ;
exception_list          : exception_list exception_hand
						{
                            
						}
                        | exception_hand
                        {
                        	
                        }
                        ;
exception_hand          : WHEN choice_sequence ARROW sequence_of_statements 
						{
                        
						printf("search for %s\n", $2);
                        
                        char *temp = (char*)malloc(40 * sizeof(char));
                        	
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "r1 = 0\n");
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                            add_PL_ex(instr-1, -7);
                        
                        

                        
                    }


                        ;
choice_sequence         : choice_sequence '|' ID
                        | ID
                        {int offset;
                            node* curr_node = search_in_stack($1, &offset);
                            jump_table[curr_node->value] = instr; 
                            $$ = $1;}
                        | OTHERS
                        {
                            for(int i = 1; i < next_exception; i++) {
                                if (jump_table[i] == 0)
                                jump_table[i] = instr;
                            }
                            
                            $$ = NULL;}
                        ;
identifier_list         : ID ',' identifier_list
                        {$3 = insert($3, $1);
                         $$ = $3; }
                        | ID
                        {LL_node head; 
                         head = init($1);
                         $$ = head;
                        }
                        ;


%%
int main()
{
  push("Outer_Context");
  node* curr_node;
  int offset;
  add("boolean");
  curr_node = search_in_stack("boolean", &offset);
  curr_node -> value = 1; 
  curr_node -> kind = "boolean";
  add("integer"); 
  curr_node = search_in_stack("integer", &offset);
  curr_node -> value = 1; 
  curr_node -> kind = "integer";
  add("true");
  curr_node = search_in_stack("true", &offset);
  curr_node -> value = 1; 
  add("false");
  curr_node = search_in_stack("false", &offset);
  curr_node -> value = 1; 
  add("maxint");
  add("read");
  curr_node = search_in_stack("read", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "read_routine";
  add("write");
  curr_node = search_in_stack("write", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "write_routine";
  add("constant_error");
  curr_node = search_in_stack("constant_error", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "exception";
  add("numeric_error");
  curr_node = search_in_stack("numeric_error", &offset);
  curr_node -> value = 2;
  curr_node -> kind = "exception";

  printf("OC tree is created!\n\n");
  yyparse();
}
