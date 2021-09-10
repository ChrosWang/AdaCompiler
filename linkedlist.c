/* ## (c) 2017, Arkadiusz Drabczyk, arkadiusz@drabczyk.org */
//https://gist.github.com/ardrabczyk/1cdc413b9eaa9a9a0c4be71d3fc9bc37
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct LL_node {
	char *data;
	struct LL_node *next;
}*LL_node;

LL_node init(char *data)
{
	LL_node new_node;
	new_node = (LL_node)malloc(sizeof(LL_node));
	new_node->data= (char*)malloc(sizeof(data)+1);
	strcpy(new_node->data, data);
	new_node->next = NULL;
	return new_node;
}

LL_node insert(LL_node head, char *data)
{
	LL_node new = (LL_node)malloc(sizeof(LL_node));
	new->next = head;
	new->data= (char*)malloc(sizeof(data)+1);
	strcpy(new->data, data);
	return new;
}

void print(LL_node head)
{
	LL_node current = head;
	while (current != NULL) {
		printf("%s ", current->data);
		current = current->next;
	}
}
/*
int main(void)
{
	LL_node head;
	head = init("25");
	head = insert(head, "25");
	head = insert(head, "25");
	head = insert(head, "25");
	head = insert(head, "25");

	printf("Print the linked list:");
	print(head);


	return EXIT_SUCCESS;
}*/