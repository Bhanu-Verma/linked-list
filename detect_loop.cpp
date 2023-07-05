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

bool detectloop(node* head){
    if(head==NULL) return false;
    
    map <node*,bool> visited;
    node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true)
        return true;
        else{
            visited[temp]=true;
        temp=temp->next;
        }
    }
    return false;
}

void insert_at_head(node* &head, int x){
        node* new_node= new node(x);
        if(head==NULL){
            head=new_node;
            return;
        }
        new_node->next=head;
        head=new_node;
        return;
}

void print(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
int main(){
    node* head=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insert_at_head(head,x);
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head->next;

   if( detectloop(head)){
    cout<<"loop is present.\n"<<endl;
   }else{
    cout<<"no loop is present.\n"<<endl;
   }
    //print(head);
    return 0;
}