#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert (int x,struct node **head){
            struct node* new_node=(struct node*) malloc(sizeof(struct node));
            new_node->data=x;
            if(*head==NULL){
                new_node->next=NULL;
                *head=new_node;
                return;
            }
            struct node *temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
            new_node->next=NULL;
            return;

}

void print(struct node* head){
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
        return ;
}         

int count(struct node* head, int key){
    int ans=0;
    while(head!=NULL){
        if(head->data==key){
            ans++;         
        }
        head=head->next;
    }
    return ans;
}

int main(){
    struct node* head=NULL;
    printf("give the number of elements in your list:\n");
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        insert(x,&head);
    }
    
    printf("enter the number to be counted in the list:\n");
    int key;
    scanf("%d",&key);
    int m=count(head,key);
    printf("%d is present %d times in the list.",key,m);

    //print(head);
    
    return 0;
}