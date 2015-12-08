#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start1,*start2,*newnode,*current,*temp1,*temp2,*temp,*start,*temp3;
struct test
{
	int input1[10], size1,input2[10],size2,output[20];
}test[10] = { { { 1, 3, 5 }, 3, { 2, 4, 6 }, 3, { 1, 2, 3, 4, 5, 6 } },
{ {}, 0, {}, 0, {} },
{ {}, 0, { 1, 2, 3 }, 3, { 1, 2, 3 } },
{ { -1, 2, 3 }, 3, {}, 0, { -1, 2, 3 } },
{ { -5, -3, 0, 2, 4 }, 5, { -7, -6, 1, 3 }, 4, {-7,-6,-5,-3,0,1,2,3,4} },
{ { 1, 4, 6, 8, 110, 1400, 17000, 21000 }, 8, { -100, -10, 0, 100, 200, 1000 }, 6, {-100,-10,0,1,4,6,8,100,110,200,1000,1400,17000,21000} },
{ { 10, 100, 1000, 10000 }, 4, { 10001, 11000, 12000 }, 3, { 10, 100, 1000, 10000, 10001, 11000, 12000 } },
{ { 1, 10, 100, 200 }, 4, { -100, -10, 0 }, 3, {-100,-10,0,1,10,100,200} },
};
struct node *merge(struct node *start1, struct node *start2)
{
	if ((start1 == NULL&&start2 == NULL)||start2==NULL)
		return start1;
	if (start1 == NULL)
		return start2;
	for (temp1=temp3 = start1, temp2 = start2; temp1 != NULL&&temp1 != NULL;)
	{
		 if (temp1->data > temp2->data)
		{                     //insert before node
			temp = temp1->next;
			temp3->next = temp2;
			temp2 = temp2->next;
			(temp1->next)->next = temp;
		}
		else
			temp1 = temp1->next;
	}
	if (temp1 == NULL)
		temp3->next = temp2;
	return start1;
}
struct node *merge1(struct node *start1, struct node *start2)
{             //assuming first list as result and inserting 2nd list nodes in first list
	if ((start1 == NULL&&start2 == NULL) || start2 == NULL)
		return start1;
	if (start1 == NULL)
		return start2;
	temp1 = start1;
	temp2 = start2;
	if (start2->data <= start1->data)
	{                                       //insertion before start1
		for (temp = start2; temp->next->data <= start1->data;)
		{
			temp = temp->next;
			if (temp->next == NULL)
				break;
		}
		temp2 = temp->next;
		temp->next = start1;
		temp1 = start1;
		start1 = start2;
	}
	for (; temp1->next != NULL&&temp2 != NULL;)       //insertion at middle positions
	{
		if ((temp1->next)->data >= temp2->data)
		{
			temp = temp1->next;
			temp1->next = temp2;
			temp2 = temp2->next;
			(temp1->next)->next = temp;
			temp1 = temp1->next;
		}
		else
			temp1 = temp1->next;
	}
	if (temp1->next == NULL)          //merging at last
		temp1->next = temp2;
	return start1;
}
void display(struct node *temp1)
{
	printf("list\n");
	for (; temp1 != NULL; temp1 = temp1->next)
		printf("%d\t", temp1->data);
}
void create1(int *input,int size)
{
	char ch;
	int data,index=0;
	while (index<size)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = input[index];
		newnode->next = NULL;
		if (start1== NULL)
		{
			start1 = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
			current = newnode;
		}
		index++;
	} 
}
void create2(int *input, int size)
{
	char ch;
	int data, index = 0;
	while (index<size)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = input[index];
		newnode->next = NULL;
		if (start2 == NULL)
		{
			start2 = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
			current = newnode;
		}
		index++;
	} 

}
void printop(int index, struct node *temp4)
{
	int index1;
	for (index1 = 0; index1 < test[index].size1 + test[index].size2; index1++,temp4=temp4->next)
	{
		if (temp4->data != test[index].output[index1])
			break;
	}
	if (temp4 == NULL)
		printf("passed\n");
	else
		printf("failed\n");
}
void testing()
{
	int index;
	for (index = 0; index < 8; index++)
	{
		create1(test[index].input1, test[index].size1);
		create2(test[index].input2, test[index].size2);
		temp = merge1(start1, start2);
		printop(index, temp);
		start1 = NULL;
		start2 = NULL;
	}
}
void main()
{
	testing();
	_getch();
}