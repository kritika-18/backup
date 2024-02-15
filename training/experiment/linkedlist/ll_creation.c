#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(){
    struct node *head,*newnode,*temp;
    int choice=1;
    head=NULL;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL) head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("\nPress 1 to continue else press 0: ");
        scanf("%d",&choice);
    }
    newnode->next=NULL;
    temp=head;
    printf("\nThe list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    display();
    return 0;
    
}
