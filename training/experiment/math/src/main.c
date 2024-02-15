#include<stdio.h>
#include "add.c"
#include "sub.c"
#include "mul.c"
#include "../hdr/hdr.h"
//extern int add(int ,int);
//extern int sub(int,int);
//extern int mul(int,int);
int main(){

	int a;
	int b;
	printf("Enter the values to be added: ");
	scanf("%d",&a);
	scanf("%d",&b);
	//int res1=add(a,b);
	printf("Sum: %d",add(a,b));

	printf("Enter the values to be subtracted: ");
	scanf("%d",&a);
	scanf("%d",&b);
//	int res2=sub(a,b);
	printf("Difference: %d",sub(a,b));

	printf("Enter the values to be multilpied: ");
	scanf("%d",&a);
	scanf("%d",&b);
//	int res3=mul(a,b);
	printf("Product: %d",mul(a,b));

	return 0;
}
