#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(int x, struct node** head){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;

    if(*head==NULL){
        *head=new_node;
    }else{
        struct node* temp= *head;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void print(struct node* head){
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
        return ;
}  

void insert_at_head(int x, struct node** head){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=*head;
    *head=new_node;

}
void reverse(struct node** head){
    struct node* temp= *head;
    struct node* prev=NULL;
    struct node* curr=*head;
    while (temp!=NULL)
    {   
        insert_at_head(temp->data,head);
        temp=temp->next;
       // *head=temp;
       
       //free(temp);

    }
    
    
}

int main(){
    struct node* head=NULL;
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        insert(arr[i],&head);
    }
    
   
    
    reverse(&head);
     print(head);
    
    return 0;
}