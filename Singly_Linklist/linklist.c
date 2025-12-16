// Program to implement Singly Linklist.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*first, *temp, *last, *temp1;

void main(){
void create();
void display();
void insertfirst();
void insertlast();
void insertbetwn();
void deletefirst();
void deletelast();
void deletebtn();
void ext();
int ch=0;

    while(ch!=9){
    printf("\nEnter Your Choice: \n");
    printf("\n 1.Create \n 2.Display \n 3.Insertion at first \n 4.Insertion at last\n 5.Insertion in between \n 6.Deletion at first  \n 7.Deletion at last \n 8.Deletion in between \n 9.Exit.\n");
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
        insertlast();
        break;

    case 5:
        insertbetwn();
        break;

    case 6:
        deletefirst();
        break;

    case 7:
        deletelast();
        break;

    case 8:
        deletebtn();
        break;    
    case 9:
        ext();
        break;    
    
    default :
       printf("End of the Program");
       break;
    
        }
                 }


}

//Create Function
void create(){
int n,i;
printf("Enter Number  of Nodes: ");
scanf("%d",&n);

first=((struct node*)malloc(sizeof(struct node)));

printf("Enter the data : ");
scanf("%d",&first->data);

first->link=NULL;
temp=first;

// for loop 
for(i=1; i<n; i++){
    last=((struct node*)malloc(sizeof(struct node)));
    last->link=NULL;
    scanf("%d",&last->data);
    temp->link=last;
    temp=last;
}

}

//Display Function
void display() {
   temp = first;
   
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    
}


// Insertion at the first.
void insertfirst() {
    temp1 = ((struct node*)malloc(sizeof(struct node)));   
    printf("Enter the data\n");
    scanf("%d", &temp1->data);

    temp1->link = first;   // new node points to old first node
    first = temp1;         // head is updated to new node
}


// Insertion at the last;
void insertlast(){
    temp1=((struct node*)malloc(sizeof(struct node)));
    
    temp=first;
    printf("Enter the data\n");
    scanf("%d",&temp1->data);
    
    while(temp->link!=NULL){
        temp=temp->link;
    } 
    temp->link=temp1;
    temp1->link=NULL;
        
}

// Insertion in between;
void insertbetwn(){
    int value;
    printf("Enter the value after which you want to enter data :\n");
    scanf("%d",&value);
printf("Enter data :\n");


    temp=((struct node*)malloc(sizeof(struct node)));
    temp->link=NULL;
    scanf("%d",&temp->data);

    temp1=first;
    while(temp1->link!=NULL){
        if(temp1->data==value){
            temp->link=temp1->link;
            temp1->link=temp;
            break;
        }
temp1=temp1->link;
    }
}


//deletion at first
void deletefirst(){
    
    temp=first;
    if(temp==NULL){
        printf("\nEmpty list");

    }
    printf("%d",temp->data);
    first=first->link;
    temp->link=NULL;
    free(temp);

}

//deletion at last
void deletelast(){
   temp=first;
   while(temp->link!=NULL){
    temp1=temp;
    temp=temp->link;

   }
   temp1->link=NULL;
   free(temp);
}

//delection in between;
void deletebtn(){
    int value;
    printf("Enter the value:\n");
    scanf("%d",&value);
    temp=first;
    temp1=temp;

    while(temp->link!=NULL){

        if(temp->data==value){
            temp1->link=temp->link;
            temp->link=NULL;
           printf("%d",temp->data);
         free(temp);
           break;
           
       
    }
    temp1=temp;
           temp=temp->link;
}
}

//Exit of the Code.
void ext(){
    exit(0);

}