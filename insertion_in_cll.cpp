#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x){
        this->data=x;
        this->next=NULL;
    }
};

void insert_in_empty(node* &last, int data){
   
}

void insert_at_head(node* &last, int data){
    if(last==NULL){
        node* new_node=new node(data);
        new_node->next=new_node;
        last=new_node;
        return;
    }
    
    node* new_node=new node(data);
    new_node->next=last->next;
    last->next=new_node;
    return;
}

void insert_at_last(node* &last, int data){
    if(last==NULL){
        node* new_node=new node(data);
        new_node->next=new_node;
        last= new_node;
        return;
    }

    node* new_node=new node(data);
    new_node->next=last->next;
    last->next=new_node;
    last=new_node;
    return;
}

void insert_at_middle(node* &last, int a, int ele){
    if(last==NULL){
        node* new_node=new node(a);
        new_node->next=new_node;
        last= new_node;
        return;
    }

    node* new_node=new node(a);
    node* temp=last->next;
    while(temp->data!=ele){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}

void print(node* last){
    if(last==NULL){
        cout<<"list is empty\n";
        return;
    }

    node* temp=last->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=last->next);
    return;
}

int main(){
    node* last=NULL;
    insert_at_head(last,10);
    insert_at_head(last,20);
    insert_at_last(last,30);
    int a,ele;
    cout<<"the element that you want to insert:\n";
    cin>>a;
    cout<<"the element after which you want to insert it:\n";
    cin>>ele;
    insert_at_middle(last,a,ele);
    print(last);
    
    return 0;
}