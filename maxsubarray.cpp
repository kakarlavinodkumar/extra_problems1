#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int input[10], size, output;
}test[10] = { { { -4, -5, -1, -2, -3 }, 5, -1 },
{ {-100},1,-100 },
{ {0,0,0,0,0},5,0 },
{ { 1, 2, 3, 4, 5, -5 }, 6, 15 },
{ { 1, 2, 3, 4, -4, 5, -1 }, 7, 11 },
{ { 0, 0, -100,-1 }, 4, 0 },
{ {0,-1,-2,-3},4,0 },
{ { 1, 2, 3,  5, -10, 20, 40 }, 7, 61 },
{{1,2,3,4,5,-2,-3,-4,-20,10},10,15}
};
int maximumsubarraysum1(int *arr, int size)
{
	int index, currentsum, maxsum;
	for (currentsum = maxsum = arr[0], index = 1; index < size; index++)
	{
		if (arr[index] <  currentsum+arr[index])   
			currentsum += arr[index];
		else                                        //previous negative sum ignored
			currentsum = arr[index];
		if (maxsum < currentsum)
			maxsum = currentsum;
	}
	return maxsum;
}
int maximumsubarraysum(int *arr,int size)
{
	int index1, index2, sum, maxsum;
	for (index1 = 0,maxsum=arr[0]; index1 < size; index1++)
	{
		for (sum=0,index2 = index1; index2 < size; index2++)
		{
			sum += arr[index2];
			if (sum>maxsum)
				maxsum = sum;
		}
	}
	return maxsum;
}
void printop(int expected, int actual)
{
	if (expected == actual)
		printf("passed\n");
	else
		printf("failed\n");
}
void testing()
{
	int index,op;
	for (index = 0; index < 9; index++)
	{
		op = maximumsubarraysum(test[index].input, test[index].size);
		printop(op, test[index].output);
	}
}
void main()
{
	testing();
	_getch();
}