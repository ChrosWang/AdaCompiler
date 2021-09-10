#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct patch_list_node {
  int patch_line;
  int content;
  struct patch_list_node *next;
}PL_node;

PL_node* create_new_node_PL (int line, int content) {
  PL_node* new_node; 
  new_node = (PL_node*)malloc(sizeof(PL_node));
  new_node-> patch_line = line;
  new_node-> content = content; 
  new_node-> next = NULL;

  return new_node;
}
#define MAX_SIZE_PL  999
PL_node* stack_PL[MAX_SIZE_PL];
PL_node* stack_PL_ex[MAX_SIZE_PL];
PL_node* Patch_list;
int count_PL = 0; 
int count_PL_ex = 0; 
int push_PL();
PL_node* recursive_insert_PL(PL_node* sub_root, int line, int content);

void add_PL(int line, int content){
    stack_PL[count_PL] = recursive_insert_PL(stack_PL[count_PL], line, content);
}
void add_PL_ex(int line, int content){
    stack_PL_ex[count_PL_ex] = recursive_insert_PL(stack_PL_ex[count_PL_ex], line, content);
}

PL_node* recursive_insert_PL(PL_node* sub_root, int line, int content){
  if (sub_root == NULL) { 
    sub_root = create_new_node_PL(line, content);

  } else {
    sub_root->next = recursive_insert_PL(sub_root->next, line, content);
  }
  return sub_root;
}

int search_PL(PL_node* sub_root, int line) {
  if (sub_root == NULL) { 
    return -1;
  } else if (sub_root->patch_line == line) {
    return sub_root->content;
  }
  else {
    return search_PL(sub_root->next, line);
  }
}




int push_PL()
{
  if (count_PL >= MAX_SIZE) {
    return -1;
  } else {
    count_PL++;
    stack_PL[count_PL] = NULL;
    return 0; 
  }
}
int pop_PL() {
  if (count_PL == 0)
    return -1;
  else 
    count_PL--; 
  
  return 0; 
}
int size_PL() {
  return count_PL;
}
PL_node* retrieve_PL(){
  return stack_PL[count_PL];
}


int push_PL_ex()
{
  if (count_PL_ex >= MAX_SIZE) {
    return -1;
  } else {
    count_PL_ex++;
    stack_PL_ex[count_PL_ex] = NULL;
    return 0; 
  }
}
int pop_PL_ex() {
  if (count_PL_ex == 0)
    return -1;
  else 
    count_PL_ex--; 
  
  return 0; 
}
int size_PL_ex() {
  return count_PL_ex;
}
PL_node* retrieve_PL_ex(){
  return stack_PL_ex[count_PL_ex];
}



PL_node* patch_jump(PL_node* sub_root, int content){
  if (sub_root == NULL) { 

  } else {
    if (sub_root->content == -7) sub_root->content = content;
    sub_root->next = patch_jump(sub_root->next, content);
  }
  return sub_root;
}

PL_node* patch_jump_ex(PL_node* sub_root, int target, int content){
  if (sub_root == NULL) { 

  } else {
    if (sub_root->content == target) sub_root->content = content;
    sub_root->next = patch_jump_ex(sub_root->next,target, content);
  }
  return sub_root;
}

void print_PL(PL_node* sub_root) {
  if(sub_root == NULL) {printf("empty patch list\n");}
  else if(sub_root->next == NULL) {printf("line: %d, content: %d\n", sub_root->patch_line, sub_root->content); printf ("DONE printing\n");}
  else {
    printf("line: %d, content: %d\n", sub_root->patch_line, sub_root->content);
    print_PL(sub_root->next);
  }
}
PL_node* toEnd_PL(PL_node* sub_root){
  if (sub_root == NULL) return sub_root;
  if(sub_root->next == NULL) {return sub_root;}
  else {
    return toEnd_PL(sub_root->next);
  }
}
void add_rear_PL(int line, int content){
  PL_node* curr_node = toEnd_PL(Patch_list);
  if (curr_node != NULL)
  curr_node->next = create_new_node_PL(line, content);
  else
  Patch_list = create_new_node_PL(line, content);
}