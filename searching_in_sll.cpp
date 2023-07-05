#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x, node* y){
        this->data=x;
        this->next=y;
    }
};

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

bool search(int x, node* head){
    while(head!=NULL){
        if(head->data==x) return true;
        head=head->next;
    }
    return false;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return ;
}


int main(){
    node *head=NULL;
     int n;
    cout<<"give the number of elements to be inserted at the head of your linked list:\n";
    cin>>n;
    cout<<"give the elements of your linnked list:\n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_tail(head,x);
    }
    
    if(search(4,head)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }

    return 0;
}