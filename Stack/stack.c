// Stack Implementation using Linked list.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*top=NULL,*temp;



int main(){
    void push();
    void display();
    void pop();
    void ext();
    int ch=0;
    while(ch!=5){
        printf("\nEnter Your Option:\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Pop\n");
        printf("4. Exit\n");
        
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push();
            break;

            case 2:
            display();
            break;

            case 3:
            pop();
            break;
            
            case 4:
            ext();
            break;

        }
    }
}

// Push Function
void push(){
    int n;
    printf("\nEnter the data \n");
    temp = ((struct node*)malloc(sizeof(struct node)));
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}
//Display Function
void display(){
     temp=top;
     printf("\nlist of the value:\n");
     while(temp!=NULL){
        printf("%d-",temp->data);
        temp=temp->link;

     }
}
// Pop Function
void pop(){
if(top==NULL){
    printf("\nlist empty\n");
}else{
    temp=top;
    printf("%d",temp->data);

    top=top->link;
    free(temp);
}
}

// Exit Function 
void ext(){
exit(0);
}
