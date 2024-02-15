#include <stdio.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void sort(int arr[],int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(arr[i]<arr[j]) swap(&arr[i],&arr[j]);
        }
    }
    
    
    
    
}


void merge(int arr1[],int arr2[],int n,int m){
    int arr3[n+m];
    int i,j;
    for(i=0;i<n;i++){
        arr3[i]=arr1[i];
    }
    for(j=0;j<m;j++){
        arr3[i]=arr2[j];
        i++;
    }
    sort(arr3,n+m);
    
    print(arr3,n+m);
    
    
}
int main()
{
    int n;
    printf("Enter first array's size: ");
    scanf("%d",&n);
    
    int m;
    printf("Enter second array's size: ");
    scanf("%d",&m);
    
    int arr1[n];
    int arr2[m];
    int arr3[n+m];
    printf("\nEnter first array's elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    
    printf("\nEnter second array's elements: ");
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    
    printf("\nFinal array: ");
    
    merge(arr1,arr2,n,m);
    

    return 0;
    
}
