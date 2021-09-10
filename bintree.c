#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct binary_tree_node {

  char *symbol;
  char *kind;
  struct binary_tree_node *parent_type;
  int value;
  char *mode;
  struct binary_tree_node *next;
  struct binary_tree_node *component_type;
  int lower;
  int upper;
  int proc_begin;

  struct binary_tree_node *left;
  struct binary_tree_node *right;
}node;
/*
 node * new(char symbol) {
 node * n = malloc(sizeof(node));
 node->symbol = symbol;
 n->left = NULL;
 n->right = NULL;
 }
 */
node* empty_node (node* new_node) {
  new_node->kind = NULL;
  new_node->parent_type = NULL;
  new_node->value = 0;
  new_node->mode = NULL;
  new_node->next = NULL;
  new_node->component_type = NULL;
  new_node->lower = 0;
  new_node->upper = 0;
  new_node->proc_begin = 0;

  return new_node;
}
node* create_new_node () {
  node* new_node; 
  new_node = (node*)malloc(sizeof(node));
  new_node->symbol = NULL;
  new_node->kind = NULL;
  new_node->parent_type = NULL;
  new_node->value = 0;
  new_node->mode = NULL;
  new_node->next = NULL;
  new_node->component_type = NULL;
  new_node->lower = 0;
  new_node->upper = 0;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->proc_begin = 0;

  return new_node;
}

typedef struct ele_array {
  char name[20];
  node *root;
}element_array;
/*
 element_array * new(char name) {
 element_array * e = malloc(sizeof(element_array));
 e -> name = name;
 e -> root = NULL;
 }
 */
#define MAX_SIZE  999

element_array stack_b[MAX_SIZE];
int count = 0; 
node* recursive_search_local(node * current_node, char target[]);
void add(char* target);
node* recursive_insert(node * sub_root, char* target);
void present(node * current_node);
/*
 //binary tree functions
 int insert(node new_node);
 int recursive_insert()
 
 int makeEmptyTree();
 
 //stack functions￼

 int push(node b_entry);
 int pop();
 int size();
 int add(new_item);
 int search_in_stack(char target);
 */
void present(node * current_node) {
    if (stack_b[count-1].root == NULL) {
        printf("Empty tree");
    } else if (current_node == NULL) {
    } else {
      if(strcmp(current_node -> kind, "type (array)") == 0) {
        printf("%s - %s w/ component type %s\n", current_node->symbol, current_node->kind, current_node->component_type->symbol); 
      } else if(strcmp(current_node -> kind, "type (range)") == 0) {
        printf("%s - %s\n", current_node->symbol, current_node->kind); 
     // } else if (strcmp(current_node -> kind, "procedure") == 0 ) {
     //   printf("%s - %s\n", current_node->symbol, current_node->kind); 
     // } else if (strcmp(current_node -> kind, "parameters") == 0 && current_node->next != NULL){
     //   printf("%s - %s w/ next parameter %s\n", current_node->symbol, current_node->kind, current_node->next->symbol); 
     // } else if(strcmp(current_node -> kind, "parameters") == 0){
      //  printf("%s - %s w/ next parameter %s\n", current_node->symbol, current_node->kind, "NULL");
      } else if(strcmp(current_node -> kind, "variable") == 0) {
        printf("%s - %s w/ parent type %s\n", current_node->symbol, current_node->kind, current_node->parent_type->symbol); 
      } else if(strcmp(current_node -> kind, "parameters") == 0)   {
        printf("%s - %s w/ parent type %s\n", current_node->symbol, current_node->kind, current_node->parent_type->symbol);  
      } else {
        printf("%s - %s\n", current_node->symbol, current_node->kind); 
      }
        present(current_node -> left);
        present(current_node -> right);
    }
}

node* recursive_search_local(node * current_node, char *target) {
  if (current_node == NULL) {
    return NULL;
  }else {
    //printf("Looking at Symbol is %s, target is %s.\n", current_node->symbol, target);
    if (strcmp(current_node->symbol, target) == 0) {
      //printf("Symbol is %s, target is %s.\n", current_node->symbol, target);
      return current_node; 
    } else if (strcmp(current_node->symbol, target) < 0) {
    return recursive_search_local(current_node->right, target);
    }else if (strcmp(current_node->symbol, target) > 0) {
    return recursive_search_local(current_node->left, target);
  }
  }
}

void add(char *target){
    if (recursive_search_local(stack_b[count-1].root,target) == NULL) {
    stack_b[count-1].root = recursive_insert(stack_b[count-1].root, target);
    }
}

node* recursive_insert(node * sub_root, char *target){
  if (sub_root == NULL) { 
    sub_root = (node*)malloc(sizeof(node));
    sub_root->left = NULL;
    sub_root->right = NULL;
    sub_root->symbol= (char*)malloc(sizeof(target)+1);
    strcpy(sub_root->symbol, target);
    
  } else if (strcmp(sub_root->symbol, target) < 0) {
    sub_root->right = recursive_insert(sub_root->right, target);
  } else if (strcmp(sub_root->symbol, target) > 0){
    sub_root->left = recursive_insert(sub_root->left, target);
  }
  return sub_root;
}


int push(char name[])
{
  if (count >= MAX_SIZE) {
    return -1;
  } else {
    count++;
    strcpy(stack_b[count].name, name);
    stack_b[count].root = NULL;
   // printf("\nwe have %d tree in the stack.", count);
    //printf("\nname of the tree is %s\n", stack_b[count].name);
    return 0; 
  }
}

int pop() {
  printf("pop tree %s off!\n", stack_b[count].name);
  if (count == 0)
    return -1;
  else 
    count--; 
  
  return 0; 
}

int size() {
  return count;
}

node* search_in_stack(char target[], int *offset) {
    int i = count-1;
    node* outcome;
    *offset = i; 
  while (i >= 0) {
    //printf ("Searching the %s tree...\n", stack_b[i].name);
    outcome = recursive_search_local(stack_b[i].root, target);
    //printf("search the %d tree.\n", i);
    if (outcome != NULL) {*offset = count - 1 - i; return outcome;}
    i--;
    
    
  }
  return NULL;
}
/*
int main() {
  char choice = 'Q';
  char *push_ch;
  char *insert_ch;
  char *search_ch;
  char answer[20];
  int outcome = -1;
  int true = 0;
  node* new_Node = create_new_node();
  do{
    printf("\nMenu: \nP(U)sh - Push a new empty tree onto the stack. \np(O)p - Pop the top tree off the stack. \n(A)dd - Add a symbol to the binary tree on the top of the stcak. \n(S)earch - Search for a symbol.\n(P)resent - the whole tree on the top. \n(Q)uit - Quit the program. \nEnter your choice:");
    
    scanf(" %c", &choice); 
    switch(choice) {
    case 'U':
      push();
      break;
    case 'O':
      printf("Pop tree %s off.\n", stack_b[count-1].name); 
      if (pop() != 0)
        printf("The stack is empty.");  
      break;
    case 'A':
      printf("\nEnter a character you want to add to the tree: ");
      scanf("%s", answer);
      insert_ch = answer;
      add(insert_ch);
      printf("\nAdd %s in.\n", insert_ch);
      break;
    case 'S':
      printf("\nEnter a character you want to search: ");
      scanf("%s", answer);
      search_ch = answer;
      if (search_in_stack(search_ch) != NULL) {
        printf("\nFound\n");
      } else {
        printf("\nNot Found\n");
      }
      break;
    case 'P':
      printf("\npresent the tree:\n");
      present(stack_b[count-1].root);
      break;
    case 'Q':
      printf("\nyou entered Q");
      break;
    default:
      printf("\nother letters");
      break;
    }
  } while (choice != 'Q');
  
  printf("\nbye!\n");
  return 0;
}

*/
