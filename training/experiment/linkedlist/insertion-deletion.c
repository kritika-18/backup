#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a given position in the linked list
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }

    struct Node* newNode = createNode(value);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

struct Node* delete_at_begin(struct Node* head){
    if(head==NULL) printf("Empty list");
    else{
        struct Node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

struct Node* delete_at_end(struct Node* head){
    struct Node* temp;
    struct Node* prevnode=NULL;
    if(head==NULL) {
        printf("Empty list");
        return NULL;
    }
    temp=head;
    
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    if(prevnode==NULL) {
        free(head);
        return NULL;
    }
    else {
        prevnode->next=NULL;
        free(temp);
    }
    return head;
}

struct Node* delet_at_position(struct Node* head,int  position){
    int i=1;
    struct Node* temp;
    struct Node* nextnode;
    if(head==NULL) {
        printf("Empty list");
        return NULL;
    }
    temp=head;
    //if(head==NULL) printf("Empty list");
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position1,position2;

    do {
        printf("\nLinked List Operations\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at a Given Position\n");
        printf("4. Display the Linked List\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at a given Position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position1);
                head = insertAtPosition(head, value, position1);
                break;

            case 4:
                printf("Linked List: ");
                displayList(head);
                break;
                
            case 5:
                head=delete_at_begin(head);
                break;
                
            case 6:
                head=delete_at_end(head);
                break;
                
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d",&position2);
                head=delet_at_position(head,position2);
                break;

            case 0:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}

