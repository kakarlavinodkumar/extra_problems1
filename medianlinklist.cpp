//program to find median of sorted linkedlist
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL, *current,*newnode, *temp1,*temp2;
struct test
{
	int input[10], size;
	float output;
}test[10] = { { { 1 }, 1, 1 },
{ { 100, 1000 }, 2, 550 },
{ {-100,-50,0,0,100,10000},6,0 },
{ {-10000,-1000,-100,0,100,1000,10000},7,0 },
{ { 0, 0, 0, 0, 0, 0, 0, 0 }, 8, 0 },
{ { 2, 6, 10, 17, 18, 22, 26, 30 }, 8, 17.5 },
{ { 1, 2, 3, 4, 5, 6 }, 6, 3.5 },
{ { -10000, -9000, -8000, -7000, -6000, -5000, -4000 }, 7, -7000 },
{ {-100,-90,-50,-1,0,50,100,1000,10000},9,0 }
};
float median1(struct node *start)           //1st method     
{                                
	for (temp1 = temp2=start; ;temp1=temp1->next,temp2=(temp2->next)->next)
	{                        //using short pointer and long pointer
		if (temp2->next == NULL)
			return temp1->data ;
		if ((temp2->next)->next == NULL)
			return ((float)temp1->data+(temp1->next)->data)/2;
	}
}
float median2(struct node *start)         //2nd method by counting number of nodes
{
	int count,flag;
	if (start->next == NULL)
		return start->data;
	for (count = 0, temp1 = start; temp1 != NULL; temp1 = temp1->next)
		count++;           //counting nodes
	for (flag = 1, temp1 = start; flag < count / 2; flag++)
		temp1 = temp1->next;          //upto n/2th node
	if (count % 2 == 0)              
		return ((float)temp1->data + (temp1->next)->data) / 2;
	return (temp1->next)->data;
}
void create(int index)
{
	char ch;
	int index1;
	for (index1 = 0; index1 < test[index].size;index1++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = test[index].input[index1];
		newnode->next =NULL;
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
	for (temp1 = start; temp1 != NULL; temp1 = temp1->next)
		printf("%d\t", temp1->data);
}
void printop(float actual, float expected)
{
	//printf("actual\t%f\texpected\t%f\n", actual, expected);
	if (actual == expected)
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
		printop(median2(start), test[index].output);
		start = NULL;
	}
}
void main()
{
	testing();
	_getch();
}