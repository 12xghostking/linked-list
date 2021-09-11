#include <iostream>
#include <math.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void attail(node* &head,int val){
  
    node* n=new node(val); 
     if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }temp->next=n;
}
void athead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void di(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }}
bool srch(node* head,int val){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==val)
        return 1;
        temp=temp->next;
    }
    return 0;

}
void delh(node* &head){
    node* todele=head;
    head=head->next;
    delete todele;
}
void del(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delh(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* dele=temp->next;
    temp->next=temp->next->next;
    delete dele;
}
 node* rev(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* nptr;
    while(curr!=NULL){
        nptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nptr;
    }
    return prev;
} 
node* revk(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* nptr;
    int c=0;
    while(curr!=NULL&&c<k){
        nptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nptr;
        c++;
    }if(nptr!=NULL){
    head->next=revk(nptr,k);
    }
    return prev;

}
node* revrec(node* &head){
 if(head->next==NULL|| head==NULL){
        return head;
    }
node* newhead=revrec(head->next);
head->next->next=head;
head->next=NULL;
return newhead;
}
void cycleat(node* &head,int pos){
    node* temp=head;
    node* st;
    int c=0;
    while(temp->next!=NULL){
        if(c==pos){
            st=temp;
        }
        temp=temp->next;
        c++;
    }
    temp->next=st;
}
bool ccycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
                return true;
        }
    }
    return false;
}
void remcy(node* &head){
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;  
}
    
