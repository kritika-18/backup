#include<stdio.h>

int main(){
	int n;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	for(int i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}return 0;
}

