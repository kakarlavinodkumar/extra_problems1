#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	bool bit;
}*start = NULL, *current, *newnode, *temp1, *temp2;

void create()
{
	char ch;
	int data;
	do
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf_s("%d", &newnode->data);
		newnode->next = NULL;
		if (start == NULL)
		{
			start = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
			current = newnode;
		}
		printf("you want to create node\n");
		ch = _getch();
	} while (ch != 'n');
}
void display()
{
	printf("list\n");
	for (temp1 = start; temp1 != NULL; temp1 = temp1->next)
		printf("%d\t", temp1->data);
}
struct node *loop(struct node *start)
{
	for (temp1 = start; temp1 != NULL; temp1 = temp1->next)
		temp1->bit = 0;
	for (temp1 = start,start->bit=1;;)
	{
		if ((temp1->next)->bit == 1)
			return temp1;
		(temp1->next)->bit = 1;
	}
}
void main()
{
	create();
	display();
	temp1 = loop(start);
	printf("%u", temp1);
	_getch();
}