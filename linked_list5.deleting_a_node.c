#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    
};


void print(struct node **head){
    struct node *temp= *head;
    while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
    }
    return;
}

void insert(int x, struct node **head){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=x;
    if(*head==NULL){
        *head=new_node;
    }else{
        struct node* temp= *head;

        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    

}

void del(int position, struct node **head){
    struct node *temp=(struct node*) malloc(sizeof(struct node));

    struct node *prev=NULL;
    struct node *curr=*head;

    if(position==1){
        temp=*head;
        *head=curr->next;
        free(temp);
        return;
    }

    int count=1;
    while(count<position){
        prev=curr;
        curr=curr->next;
        
        count++;
    }

    temp=curr;
    prev->next=curr->next;
    free(temp);
    return ;
}

int main(){
    struct node *head=NULL;
    /*insert(10,&head);
    insert(20,&head);*/

    /*copying array in a linked list */
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++){
        insert(arr[i],&head);
    }
    printf("linked list before deleting the 3rd node:\n");
    print(&head);

            /*program to delete the 3rd node from the linked list*/

    del(3,&head);

    printf("\n\n linked list after deleting third node:\n");
    print(&head);
    return 0;

}