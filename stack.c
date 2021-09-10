#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{

	int data;
	struct node* previous;

}*node_ptr;


node_ptr top = NULL;


bool is_empty(){

	return (top == NULL);
}

int display_top(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return;
	}

	return top->data;
}

void display(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return;
	}

	node_ptr temp = top;

	printf("\n");

	while(temp != NULL){
		printf("\t[%d]\n", temp->data);
		temp = temp->previous;
	}
}

bool clear(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return false;
	}

	node_ptr current = top;
	node_ptr previous = NULL;

	while(current->previous != NULL){

		previous = current->previous;
		free(current);
		current = previous;
	}

	top = NULL;

}

bool push(int value){


	node_ptr item = (node_ptr) malloc(sizeof(struct node));

	if(item == NULL)
		return false;

	item->data = value;

	if(top == NULL)
		item->previous = NULL;
	else
		item->previous = top;

	top = item;

	return true;

}

bool pop(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return false;
	}

	node_ptr temp = top;
	free(top);
	top = temp->previous;

	return true;

}
