#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node* next;

};


void print(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    return;
}

void insertn(int x, struct node*** head){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    if(**head==NULL){
        **head=new_node;
        new_node->data=x;
        new_node->next=NULL;
        return;
    }
    struct node* temp= **head;
    while(temp->next!=NULL){
          temp=temp->next;

    }
    temp->next=new_node;
    new_node->data=x;
    new_node->next=NULL;
    
    return;
}


void insert(int x, struct node** head){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    if(*head==NULL){
        *head=new_node;
        new_node->data=x;
        new_node->next=NULL;
        return;
    }
    struct node* temp= *head;
    while(temp->next!=NULL){
          temp=temp->next;

    }
    temp->next=new_node;
    new_node->data=x;
    new_node->next=NULL;
    
    return;
}

void merge(struct node* head1, struct node* head2, struct node** new_head){
        while(head1!=NULL || head2!=NULL){
                    if((head1->data)<(head2->data)){
                        insertn((head1->data), &new_head);
                        head1=head1->next;
                        
                    }else{
                        insertn((head2->data), &new_head);
                        head2=head2->next;

                    }
        }

        if(head1==NULL){
            while(head2!=NULL){
                insertn(head2->data,&new_head);
                head2=head2->next;
            }
        }

        
        if(head2==NULL){
            while(head1!=NULL){
                insertn(head1->data,&new_head);
                head1=head1->next;
            }
        }
        return;
}

int main(){
    struct node* head1=NULL, *head2=NULL;
    struct node* new_head=NULL;
    int m,n;
    printf("give the number of elements in first list:");
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int x;
        scanf("%d",&x);
        insert(x,&head1);
    }
    printf("give the number of elements in second list:");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        insert(x,&head2);
    }
    //print(head1);
    //print(head2);
    
    merge(head1,head2,&new_head);
    insert(5,&new_head);
    print(new_head);
    return 0;
}