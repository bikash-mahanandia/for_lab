// Implementation of Queue using Linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL,*temp;

void main(){
void enqueue();
void dequeue();
void display();
void ext();
int ch=0;

    while(ch!=9){
    printf("\nEnter Your Choice: \n");
    printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display\n Exit.\n");
    scanf("%d",&ch);

switch(ch){ 
    case 1:
        enqueue();
        break;
    
    case 2:
        dequeue();
        break;

    case 3:
        display();
        break;
    case 4:
        ext();
        break;    
    
    default :
       printf("End of the Program");
       break;
    
        }
                 }


}

// Enqueue
void enqueue(){
    temp=((struct node*)malloc(sizeof(struct node)));
    // temp =(node *)malloc(sizeof(node *));
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(front==NULL && rear==NULL){
        front=rear=temp;
    }else{
        rear->link=temp;
        rear=temp;
    }
}
// Display
void display(){
    temp=front;
    while(temp!=NULL){
        printf("%d_",temp->data);
        temp=temp->link;
    }
}
// Dequeue
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty");
    }else{
        temp=front;
        printf("%d",temp->data);
        front=front->link;
        free(temp);
    }
}
// Exit.
void ext(){
    exit(1);
}