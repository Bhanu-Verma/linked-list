#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    
};

void insert(int x, struct node **head){
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=*head;
    *head=new_node;

}

void print(struct node **head){
    struct node *temp= *head;
    while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
    }
    return;
}

int main(){
    struct node *head=NULL;
   /* insert(10,&head);
    insert(20,&head);*/

    /*program to copy an array in a linked list*/
    int arr[5];
    for(int i=0; i<5; i++){
        scanf("%d",&arr[i]);
    }
    int n=sizeof(arr)/sizeof(int);

    for(int i=n-1; i>=0; i--){
        insert(arr[i],&head);
    }
    print(&head);
    return 0;
}

