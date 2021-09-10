#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
char* output[999];

typedef struct address_record {
	int offset;
	int value;
	int reg_number;
	int var_offset; 
	int var_loc;
	bool is_var;
  int exp_list[999];
  int curr_top;
  char* ID; 
}record_addr;

struct address_record * create_new_record() {
  record_addr* new_record; 
  new_record = (record_addr*)malloc(sizeof(record_addr));
  new_record->offset = 0; 
  new_record->value = 0; 
  new_record->reg_number = 0; 
  new_record->var_offset = 0; 
  new_record->is_var = false;   
  new_record->var_loc = 0;
  new_record->curr_top = 0; 
  return new_record;
}
