#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top=NULL;
int isempty(){
    return top==NULL;
}

void push(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Stack Overflow\n");
        return;
    }
    newNode->data=value;
    newNode->next=top;
    top=newNode;
}

int pop(){
    if(isempty()){
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp=top;
    int value=temp->data;
    top=top->next;
    free(temp);
    return value;
}

int peek(){
    if(isempty()){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(){
    struct Node* temp=top;
    if(isempty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice,value;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value :");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                printf("Popped :%d\n",pop());
                break;
            case 3:
                printf("Top element :%d\n",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
