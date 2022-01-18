#include<bits/stdc++.h>
using namespace std;


struct Node{
  int data;
  Node* next;
};

void print(Node *root){
  Node* newNode=root;
  while(newNode!=NULL){
    cout<<newNode->data<<" ";
    newNode=newNode->next;
  }
  cout<<endl;
}

Node* addElementStart(Node *root,int val){
Node* newNode=new Node;
newNode->data=val;
newNode->next=root;
return newNode;
}

Node* addElementEnd(Node *root,int val){
  Node* node=root;
  while(node->next!=NULL){
    node=node->next;
  }
  Node* newNode=new Node();
  node->next=newNode;
  newNode->data=val;
  newNode->next=NULL;
  return root;
}
//
Node* addElementK(Node *root,int val,int k){
  Node* node=root;

  if(k==0){
  Node* newNode=new Node();
  newNode->data=val;
  newNode->next=root;
  return newNode;
  }
  else{
  int count=1;
  while(count<k && node->next!=NULL){
    node=node->next;
    count++;
  }
  Node* newNode=new Node();
  // node->next=newNode;
  newNode->data=val;
  newNode->next=node->next;
  node->next=newNode;
  return root;
  }
}

Node* removeElementK(Node* root,int k){
  Node* node=root;
  Node* prevNode=NULL;
  if(k==0)return root->next;
  else{
  int count=0;

  while(count<k && node->next!=NULL ){
    prevNode=node;
    node=node->next;
    count++;
   
  }
  prevNode->next=node->next;
  return root;
  }
}
///
Node* reverse(Node *root){
  Node* current=root;
  Node* Next=NULL;
  Node* previous=NULL;
  while(current->next!=NULL){
    Next=current->next;
    current->next=previous;
    previous=current;
    current=Next;
  }
  current->next=previous;
  return current;
}

//print linked list using resursion
void printR(Node* root){
  if(root==NULL){
    cout<<endl;
    return;
  }
  cout<<root->data<<" ";
  printR(root->next);
  cout<<root->data<<" ";
}

//reverse using resursion
Node* reverseR(Node* root){

 if(root==NULL||root->next==NULL)return root;

 Node* rest=reverseR(root->next);
 root->next->next=root;
 root->next=NULL;
 return rest;
}
//middle element of linked list
Node* middelElement(Node* start, Node* last)
{
    if (start == NULL)
        return NULL;
 
    struct Node* slow = start;
    struct Node* fast = start -> next;
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    return slow;
}
//binary search on linkedList
Node* binarySearch(Node* root,int value){

  Node* start=root;
  Node* last=NULL;
  do{
    Node* mid=middelElement(start,last);
    if(mid==NULL)return NULL;
    if(mid->data == value)return mid;
    else if(mid->data < value)start=mid->next;
    else last=mid;
  } while(last==NULL||last!=start);
  return NULL;
}
int main() {
  Node* head=NULL;
  Node* second=NULL;
  Node* third=NULL;
  head=new Node();
  second=new Node();
  third = new Node();
head->data=1;
head->next=second;
second->data=2;
second->next=third;
third->data=3;
third->next=NULL;
cout<<"linked list"<<endl;
print(head);
cout<<"add element at start"<<endl;
head=addElementStart(head, 0);
print(head);
cout<<"add element at end"<<endl;
head=addElementEnd(head, 4);
print(head);
cout<<"add element at kth position"<<endl;
head=addElementK(head, 10, 3);
print(head);
cout<<"remove kth element"<<endl;
head=removeElementK(head,3);
print(head);
cout<<"reverse"<<endl;
head=reverse(head);
print(head);
cout<<"using resursion ---------"<<endl;
cout<<"print linked list"<<endl;
printR(head);
cout<<endl<<"reverse"<<endl;
head=reverseR(head);
print(head);
Node* middle=middelElement(head,NULL); 
cout<<"middle element "<<middle->data<<endl;
if(binarySearch(head,4))cout<<"found";

}
