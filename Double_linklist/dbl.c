//Double Linked list Implementation.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
}*first,*last,*temp,*temp1;

int main(){
    void create();
    void display();
    void insertfirst();
    void insertlast();
    void insertbtn();
    void deletefirst();
    void deletelast();
    void deletebtn();
    void ex();

    int ch=0;
    while(ch!=10){
    printf("\nEnter the choice :\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at first\n");
    printf("4.Insert at between\n");
    printf("5.Insert at last\n");
    printf("6.Delete at first\n");
    printf("7.Delete at between\n");
    printf("8.Delete at last\n");
    printf("9.exit\n");
    
    scanf("%d",&ch);

    switch(ch){
        case 1:
        create();
        break;

        case 2:
        display();
        break;

        case 3:
        insertfirst();
        break;

        case 4:
        insertbtn();
        break;

        case 5:
        insertlast();
        break;

        case 6:
        deletefirst();
        break;

        case 7:
        deletebtn();
        break;

        case 8:
        deletelast();
        break;

        case 9:
        ex();
        break;

        default:
        printf("this is default");
        break;
    }
    }

}

//Create
void create(){
    int n,i;
    printf("Enter the number of nodes :\n");
    scanf("%d",&n);

    first=((struct node*)malloc(sizeof(struct node)));
    printf("Enter the data :\n");
    scanf("%d",&first->data);

    first->next=NULL;
    first->prev=NULL;
    temp=first;

    for(i=1;i<n;i++){
        last=((struct node*)malloc(sizeof(struct node)));
        last->next=NULL;
        last->prev=NULL;
        scanf("%d",&last->data);

        temp->next=last;
        last->prev=temp;
        temp=last;
    }
}

//Display
void display(){
    temp=first;
     
    while(temp!=NULL){
        printf("<-%d->",temp->data);
        temp=temp->next;
    }
}

//Insert at first
void insertfirst(){
    temp=((struct node*)malloc(sizeof(struct node)));
    printf("Enter the data :\n");
    scanf("%d",&temp->data);

    temp->next=NULL;
    temp->prev=NULL;

    temp->next=first;
    first->prev=temp;

    first=temp;
}

//Insert at last
void insertlast(){
    temp1=((struct node*)malloc(sizeof(struct node)));
    printf("Enter the data :\n");
    scanf("%d",&temp1->data);

    temp1->prev=NULL;
    temp1->next=NULL;
    temp=first;

    while(temp->next!=NULL){
        temp=temp->next;
    }
        temp->next=temp1;
        temp1->prev=temp;
        temp1->next=NULL;
    
}

//Insert between
void insertbtn(){
    int value;
    printf("Enter the value :\n");
    scanf("%d",&value);
 
    temp=((struct node*)malloc(sizeof(struct node)));
    printf("Enter the value:\n");
    scanf("%d",&temp->data);

    temp->next=NULL;
    temp->prev=NULL;

    temp1=first;

    while(temp1!=NULL){
        if(temp1->data==value){
            temp->prev=temp1;
            temp->next=temp1->next;
            temp1->next=temp;
            temp1->next->prev=temp;

        }
      temp1=temp1->next;
    }
     
}

//Delete First
void deletefirst(){
    temp=first;
    printf("Delete data :%d",temp->data);
    first=first->next;
    temp->next=NULL;
    free(temp);
}

//Delete Last
void deletelast(){
    temp=first;
    while(temp->next!=NULL){
        temp1=temp;
        temp=temp->next;
        
   
    }
     temp1->next=NULL; 
     temp->prev=NULL;
    printf("%d",temp->data);
    free(temp);
   
   
}

//Delete Between
void deletebtn(){
    int value;
    printf("Enter the value :\n");
    scanf("%d",&value);

    temp=first->next;
    temp1=first;

    while(temp!=NULL){
        if(temp1->data==value){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next->prev=temp1;
        temp->next=NULL;
        free(temp);
break;
    }
temp1=temp;
temp=temp->next;
}

//Exit
void ex(){
    exit(0);
}