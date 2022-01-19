#include <bits/stdc++.h>
using namespace std;
struct BstNode{
  int data;
  BstNode* left;
  BstNode* right;
};
BstNode* insert(BstNode* root,int val){
  BstNode* newNode=new BstNode();
  newNode->data=val;
  newNode->left=NULL;
  newNode->right=NULL;
  if(root==NULL){ 
  return newNode;
  }
  if(val<=root->data){
    root->left=insert(root->left,val);
  }
  else{
    root->right=insert(root->right,val);
  }
  return root;
}
bool search(BstNode* root,int val){
  if(root==NULL)return false;
  if(root->data==val) return true;
  else if(val<root->data){
    return search(root->left,val);
  }
  else {
    return search(root->right,val);
  }
  return false;
}
int Min(BstNode* root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root->data;
}
int Max(BstNode* root){
  while(root->right!=NULL){
    root=root->right;
  }
  return root->data;
}
//height of tree
int height(BstNode* root){
  if(root==NULL){
    return -1;
  }
  return max(height(root->left),height(root->right))+1;
}
//tree traversal

//leve order traversal
void levelOrder(BstNode* root){
  queue<BstNode*>q;
  if(root==NULL)return;
  q.push(root);
  while(!q.empty()){
    BstNode* Node=q.front();
    q.pop();
    cout<<Node->data<<" ";
    if(Node->left!=NULL)
    q.push(Node->left);
    if(Node->right!=NULL)
    q.push(Node->right);
    
  }
  cout<<endl;
}
//preOrder traversal
void preOrder(BstNode* root){
  if(root==NULL)return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

//is bst
bool isBst(BstNode* root,int minV,int maxV){
  if(root==NULL)return true;

  if(root->data > minV && root->data < maxV 
     && isBst(root->left,minV,root->data)
     && isBst(root->right,root->data,maxV)){
       return true;
     }
     else return false;

}
int main() {
  std::cout << "Hello World!\n";
  BstNode* root=NULL;
  root=insert(root,5);
  root=insert(root,10);
  root=insert(root,4);
  root=insert(root,3);
  root=insert(root,20);
  root=insert(root,25);
  root=insert(root,8);
  root=insert(root,12);
// root->data=-5;

  if(search(root,20))cout<<"found"<<endl;
  else cout<<"not found"<<endl;
cout<<"minimum element is "<<Min(root)<<endl;
cout<<"maximum element is "<<Max(root)<<endl;
cout<<"height of tree is "<<height(root)<<endl;
levelOrder(root);
preOrder(root);
cout<<endl;
if(isBst(root,INT_MIN,INT_MAX))cout<<"this is bst"<<endl;
else cout<<"not a bst"<<endl;
} 
