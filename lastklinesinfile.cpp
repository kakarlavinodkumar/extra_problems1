//program to print last k lines in file
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int countlines(char *filename)
{
	int count;
	FILE *file;
	char ch;
	fopen_s(&file,filename, "r");
	ch = getc(file);
	for (count = 0; ch != EOF; ch = getc(file))
	{
		if (ch == '\n')
			count++;
	}
	fclose(file);
	return count;
}
void lastklines1(char *filename,int k)        //1st method by counting lines and printing from n-k th line
{
	int total, count;
	FILE *file;
	char ch;
	total = countlines(filename);
	if (k > total)
		k = total;
	fopen_s(&file, filename, "r");
	ch = getc(file);
	for (count = 0; count < total - k; ch = getc(file))
	{
		if (ch == '\n')
			count++;
	}
	for (; ch != EOF; ch = getc(file))
		printf("%c", ch);
	fclose(file);
}
void lastklines2(char *filename, int k)
{
	int total, count;
	FILE *file1, *file2;
	char ch1, ch2;
	total = countlines(filename);
	if (k > total)
		k = total;
	fopen_s(&file1, filename, "r");
	ch1 = getc(file1);
	for (count = 0; count< total - k; ch1 = getc(file1))
	{                      //moving first pointer to n-kth line
		if (ch1 == '\n')
			count++;
	}
	fopen_s(&file2, filename, "r");
	ch2 = getc(file2);          //placing second pointer at start
	for (count = 0; count < k; ch2 = getc(file2),ch1=getc(file1))
	{
		if (ch2 == '\n')
			count++;
		printf("%c", ch1);      //printing last k lines
	}
	fclose(file1);
	fclose(file2);
}
bool validate(int k)
{
	if (k <= 0)
		return 0;
	return 1;
}
void test(char *filename,int k)
{
	if (validate(k))
		lastklines1(filename, k);
}
void main()
{
	test("0,1,2sort.cpp",10);
	_getch();
}