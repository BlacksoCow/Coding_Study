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
	Node* head = (Node*)malloc(sizeof(Node)); // Initialized head as dummy node
	head->next = NULL;
	Node* tail = head;
	Node* cur = NULL;
	Node* newNode = NULL;
	int data;
	while(1)
	{
		fputs("Input data: ", stdout);
		scanf("%d", &data);
		if(data < 1) // Insert data until data < 1
			break;
		newNode = (Node*)malloc(sizeof(Node));
		Insert(newNode, data);
		tail->next = newNode;
		tail = newNode;
	}
	putchar('\n');
	cur = head->next;
	if(cur == NULL)
	{
		puts("List is empty. No data to print or delete.");
		puts("Deleting dummy node.");
		free(head);
		puts("All data deleted");
		return 0;
	}
	while(cur != NULL)
	{
		printf("Data: %d\n", cur->data);
		cur = cur->next;
	}
	puts("All data printed\n");
	Node* delNode = head;
	Node* delNodenext = head->next;
	while(delNodenext != NULL)
	{
		delNode = delNodenext;
		delNodenext = delNode->next;
		puts("Deleting data");
		free(delNode);
	}
	puts("Deleting dummy node.");
	free(head);
	puts("All data deleted");
	return 0;
}