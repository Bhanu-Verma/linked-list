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

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return ;
}

void dlt(node* &head, int ele){
      //node* temp=head;
      node* prev=NULL;
      node* curr=head;
      while(curr!=NULL){
        if(curr->data==ele && prev!=NULL){
            node* temp=curr;
            
            prev->next=curr->next;
            temp->next=NULL;
            delete temp;
            return;
        }else if(curr->data==ele && prev==NULL){
           
            node* temp= curr;
            head=curr->next;
            temp->next=NULL;
            delete temp;
            return;
        }
            prev=curr;
            curr=curr->next;
      }
    if(curr==NULL){
        cout<<"element not found in the list"<<endl;
    }
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
    int ele;
    cout<<"give the element to delete from the linked list";
    cin>>ele;

    dlt(head,ele);
    print(head);
    return 0;
}