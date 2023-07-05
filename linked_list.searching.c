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

void search(int key, struct node **head){
        struct node* temp= *head;
        while(temp!=NULL){
            if(key==temp->data){
                printf("element found\n");
                return;
            }
            temp=temp->next;
        }
    
    printf("element not found\n");
    return;
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
   // print(&head);
       search(5,&head);     //here we can put a user input but now I am not getting input
    return 0;

            /*now searching using linked list*/
    


}