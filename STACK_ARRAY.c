#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
int isfull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isempty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int value){
    if(!isfull()){
        top++;
        stack[top]=value;
    }
}
int pop(){
    int del;
    if(isempty()){
        del=stack[top];
        top--;
    }
    return del;
}
int peek(){
    int p;
    if(!isempty()){
        p=stack[top];
    }
    return p;
}
void display(){
    int i;
    if(!isempty()){
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}
int main(){
    int choice,value,result;
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf("ENTER CHOICE :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("ENTER VALUE TO PUSH :");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                result=pop();
                printf("DELETED VALUE :%d\n",result);
                break;
            case 3:
                result=peek();
                printf("TOP VALUE :%d\n",result);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
