// Implementation of Double Circular Linked List.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*first,*last,*temp,*temp1;

int main(){
void create();
void display();
void insertfirst();
void insertbtn();
void insertlast();
void deletefirst();
void deletelast();
void deletebtn();
void ext();
int ch=0;

    while(ch!=10){
  printf("\nEnter Your Choice:\n\n1. Create\n2. Display\n3. Insertion at First\n4. Insert in Between\n5. Insert at Last\n6. Deletion at First\n7. Delete at Last\n8. Deletion in Between\n9. Exit\n");

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
return 0;

}

// Create
void create(){
    int n,i;
    printf("Enter the number of node :\n");
    scanf("%d",&n);

    first = ((struct node*)malloc(sizeof(struct node)));
    printf("Enter the data:\n");
    scanf("%d",&first->data);

    first->next=NULL;
    first->prev=NULL;

    temp=first;

    for(i=1; i<n; i++){
          last = ((struct node*)malloc(sizeof(struct node)));
          scanf("%d",&last->data);
          last->next=NULL;
          last->prev=NULL;

          temp->next=last;
          last->prev=temp;

          temp=last;

          last->next=first;
          first->prev=last;
    }
}

// Display
void display(){
    temp=first;
    while(temp->next!=first){
          printf("%d->",temp->data);
          temp=temp->next;
    }
    printf("%d->",temp->data);
}

//insert first
void insertfirst(){
   // code of insertion at first;
   printf("Enter the data:\n");
   temp = ((struct node*)malloc(sizeof(struct node)));
   scanf("%d",&temp->data);

   temp->next=NULL;
   temp->prev=NULL;

   temp->next=first;
   first->prev=temp;

   temp->prev=last;
   last->next=temp;

   first=temp;
}


//insertion btn
void insertbtn(){
    int value;
    printf("Enter the value \n");
    scanf("%d",&value);

    printf("Enter the data :\n");
    temp=((struct node*)malloc(sizeof(struct node)));
    scanf("%d",&temp->data);

    temp->next=NULL;
    temp->prev=NULL;
    temp1=first;

    while(temp1->next!=first){
        if(temp1->data==value){
                temp->next=temp1->next;
                temp1->next->prev=temp;
                temp->prev=temp1;
                temp1->next=temp;
                break;
        }
        temp1=temp1->next;
    }
}

//insertion at last
void insertlast(){
    temp1=((struct node*)malloc(sizeof(struct node)));
    temp=first;

    
    while(temp->next!=first)
        temp=temp->next;
        printf("Enter the data \n");
        scanf("%d",&temp1->data);

        temp->next=temp1;
        temp1->prev=temp;
        temp1->next=first;
        first->prev=temp1;
    
}


//Delete First
void deletefirst(){
    temp=first;
    printf("Delete data :%d",temp->data);
    first=first->next;
    temp->next=NULL;
    free(temp);
    last->next=first;
    first->prev=last;
}

//deletion at last
void deletelast(){
    temp=first->next;
    while(temp->next!=first){
        temp1=temp;
        temp=temp->next;

    }
    temp1->next=first;
    first->prev=temp1;
    printf("%d",&temp->data);
    free(temp);
}

//Deletion in between
void deletebtn(){
    int value;
    printf("Enter the data :\n");
    scanf("%d",&value);
    temp=first;
    temp=temp->next;
    while(temp!=first){
        if(temp->data==value){
 
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            printf("Delete data %d ",temp->data);
           
            free(temp);
            break;
        }
           
            
            // break;
            temp=temp->next;
        if(temp==first)break;
    }
    
}
//exit code
void ext(){
    exit(0);
}