#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int x){
        this->data=x;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insert_at_head(node* &head, int x){
        node* new_node=new node(x);
        new_node->next=head;
        if(head!=NULL){
                head->prev=new_node;
        }
        
        head=new_node;
        return;
}

void print(node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        return;
}

void insert_at_tail(node* &head, int x){
    node* new_node=new node(x);
    node* temp=head;
    if(head==NULL){
        head=new_node;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    return;
}

void insert_at_middle(node* &head, int ele, int pos){
        int count=0;
        node* new_node=new node(ele);
        node* temp=head;
        while(count!=pos-1){
                temp=temp->next;
                count++;
        }
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next->prev=new_node->next;
        temp->next=new_node;

}
int main(){
    node* head=NULL;
                 /*insertion at the head*/
   #ifdef PI
   int n;
    cout<<"give the number of elements to be inserted at the head:\n";
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_head(head,x);
    }
    #endif

                /*insertion at the tail of a linked list*/
    
    int n;
    cout<<"give the number of the elements to be inserted at the tail:\n";
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_tail(head,x);
    }
    
    
    int ele,pos;
    cout<<"give the element and position to be inserted:\n";
    cin>>ele>>pos;

    insert_at_middle(head,ele,pos);
    print(head);
    

    return 0;
}