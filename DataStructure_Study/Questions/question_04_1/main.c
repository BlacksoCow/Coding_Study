#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node* next;
} Node;
void Insert(Node* pnode, int data)
{
	pnode->data = data;
	pnode->next = NULL;
	return;
}
int main(int argc, char** argv)
{
	Node* head = NULL;
	Node* newNode = NULL;
	Node* cur = NULL;
	int data;
	while(1)
	{
		fputs("Input data: ", stdout);
		scanf("%d", &data);
		if(data < 1)
			break;
		newNode = (Node*)malloc(sizeof(Node));
		Insert(newNode, data);
		newNode->next = head;
		head = newNode;
	}
	putchar('\n');
	if(head == NULL)
	{
		puts("No data to print or delete.");
		return 0;
	}
	cur = head;
	while(cur != NULL)
	{
		printf("Data: %d\n", cur->data);
		cur = cur->next;
	}
	puts("All data printed\n");
	Node* delNode = head;
	Node* delNodenext = delNode->next;
	puts("Deleting data");
	free(delNode);
	while(delNodenext != NULL)
	{
		delNode = delNodenext;
		delNodenext = delNode->next;
		puts("Deleting data");
		free(delNode);	
	}
	puts("All data deleted");
	return 0;
}