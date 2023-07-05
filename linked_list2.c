#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    
};

void p(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return;
}

int main(){
    struct node* head=NULL;
    struct node* mid=NULL;
    struct node* last=NULL;

    head   = malloc(sizeof(struct node));
    mid = malloc(sizeof(struct node));
    last   = malloc(sizeof(struct node));

    head->data=10;
    head->next=mid;
    mid->data=20;
    mid->next=last;
    last->data=30;
    last->next=NULL;
    p(head);
  // printf("%d",head->data);
    
}