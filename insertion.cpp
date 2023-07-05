#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x, node * y){
            this->data=x;
            this->next=y;
    }
};

void insert_at_head(node* &head, int x){
    node* new_node=new node(x,head);
    //new_node->data=x;
    //new_node->next=*head;
    head=new_node;

    return ;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return ;
}

void insert_at_tail(node* &head, int x){
    node* new_node=new node(x,NULL);
    if(head==NULL){
        head=new_node;
        return;
    }else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=new_node;
        return;
    }
}

void insert_at_middle(node* &head, int x, int pos){
    int count=0;
    node* new_node=new node(x, NULL);
    node* temp=head;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}

int main(){
     node* head=NULL;
            /*Insertion at head in a singly liked list*/
    #ifdef PI
    int n;
    cout<<"give the number of elements to be inserted at the head of your linked list:\n";
    cin>>n;
    cout<<"give the elements of your linnked list:\n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_head(head,x);
    }
    #endif

    /*Insertion at tail in a singly linked list*/
    int n;
    cout<<"give the number of elements to be inserted at the head of your linked list:\n";
    cin>>n;
    cout<<"give the elements of your linnked list:\n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_tail(head,x);
    }

    /*insertion at a given position in a linked list*/
    int ele,pos;
    cout<<"give the element and the position that you want to insert\n";
    cin>>ele>>pos;
    insert_at_middle(head,ele,pos);



    print(head);
    return 0;
}