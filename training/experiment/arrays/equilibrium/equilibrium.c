
#include <stdio.h>

int equilibrium(int left_sum,int right_sum,int arr[],int n){
    for(int i=1;i<n;i++){
        if(left_sum==right_sum) return i;
        else{
            left_sum+=arr[i];
            right_sum-=arr[i];
        }
        
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    int left_sum=arr[0];
    int right_sum=sum-left_sum;
    
    int res=equilibrium(left_sum,right_sum,arr,n);
    if(res>0) {
        printf("Equilibrium index is: %d",res);
    }
    else printf("\nNo such index.");

    return 0;
}





