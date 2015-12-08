#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL, *current, *newnode, *temp1;
struct test
{
	int input[10], size, output[10];
}test[10] = { { { 1000, 2000 }, 2, { 2000, 1000 } },
{ { 1, 2, 3, 4, 5 }, 5, { 5, 4, 3, 2, 1 } },
{ { 0, 0, 0, 0 }, 4, { 0, 0, 0, 0 } },
{ { -100, -50, 0, 50, 100 }, 5, { 100, 50, 0, -50, -100 } },
{ { 10, 100, 1000, 10000 }, 4, {10000,1000,100,10} },
{ { 150, 150 }, 2, {150,150} },
{ { 10, 20, 30, 20, 10 },5, {10,20,30,20,10} }
};
void reverse1(struct node** root)
{
	struct node* current;
	struct node* remain;
	if (*root == NULL)
		return;
	current = *root;
	remain = current->next;
	if (remain == NULL)
		return;
	reverse1(&remain);
	current->next->next = current;    //links reversing in back traversal
	current->next = NULL;
	*root = remain;       //making remaining part as root
}
void create(int index)
{
	char ch;
	int index1;
	for (index1 = 0; index1 < test[index].size; index1++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = test[index].input[index1];
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
	}
}
void display()
{
	printf("list\n");
	for (temp1=start; temp1 != NULL; temp1 = temp1->next)
		printf("%d\t", temp1->data);
}
void printop(int index)
{
	int index1;
	for (index1 = 0,temp1=start; index1 < test[index].size; index1++,temp1=temp1->next)
	{
		if (temp1->data != test[index].output[index1])
			break;
	}
	if (index1 == test[index].size)
		printf("passed\n");
	else
		printf("failed\n");
}
void testing()
{
	int index;
	for (index = 0; index < 7; index++)
	{
		create(index);
		reverse1(&start);
		printop(index);
	//	start = NULL;
	}
}
void main()
{
	testing();
	_getch();
}