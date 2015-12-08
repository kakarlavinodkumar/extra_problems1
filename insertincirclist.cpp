#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL, *current, *newnode, *temp1, *temp2,*temp;
struct test
{
	int input[10], size, num, output[10];
}test[10] = { { { 10, 10, 10, 10, 10, 10 }, 6, 10, { 10, 10, 10, 10, 10, 10, 10 } },  //all duplicates
{{ -100, -10, 0, 10, 100 }, 5, 1001, { -100, -10, 0, 10, 100, 1001 } },// insert after last
{ { 0, 10, 15, 1500, 2000 }, 5, -1, { -1, 0, 10, 15, 1500, 2000 } }, // insert before start
{ { -10, -5, 0, 5, 10, 100 }, 6, 1, { -10, -5, 0, 1, 5, 10, 100 } },
{ { 100 }, 1,100, {100,100} },
{ { 10 }, 1, 100, {10,100} },      //single node
{ { 100 }, 1, 10, {10,100} },
{ {}, 0, 1, {1} },            //NULL list
{ { -10, -1, 0, 1, 1, 1 }, 6, 1, { -10, -1, 0, 1, 1, 1, 1 } }
};
void create(int index)
{
	int index1;
	for (index1 = 0; index1 < test[index].size;index1++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = test[index].input[index1];
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
		newnode->next = start;
	} 
}
void display()
{
	printf("list\n");
       	for (temp1 = start; temp1->next != start; temp1 = temp1->next)
		printf("%d\t", temp1->data);
	printf("%d\n", temp1->data);
}
struct node *insert1(struct node *start, int num)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next = NULL;
	if (start == NULL)          
		return newnode;                                 
	for (temp = start;(num > (temp->next)->data||num<temp->data)&&temp->next!=start;)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
	if (num < start->data)           //insert before start
		start = newnode;
	return start;
}
void printop(struct node *start, int index)
{
	int index1;
	for (index1 = 0, temp = start; index1 < test[index].size + 1; index1++,temp=temp->next)
	{
		if (temp->data != test[index].output[index1])
			break;
	}
	if (index1==test[index].size+1)
		printf("passed\n");
	else
		printf("failed\n");
}
void testing()
{
	int index;
	for (index = 0; index < 9; index++)
	{
		create(index);
		start = insert1(start, test[index].num);
		printop(start, index);
		start = NULL;
	}
}
void main()
{
	testing();
	_getch();
}