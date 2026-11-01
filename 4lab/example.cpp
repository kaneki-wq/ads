#include<bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node* left=nullptr;
    Node* right=nullptr;
};
Node* insert(Node* root,int x){
    if(root==nullptr){
        return new Node{x};
    }
    if(x<root->value){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}
void inorder(Node* root,int& k,int& answer){
    if(root==nullptr){
        return;
    }
    inorder(root->left,k,answer);
    k--;
    if(k==0){
        answer=root->value;
        return;
    }
    inorder(root->right,k,answer)
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);
    int n,k;
    cin>>n>>k;
    Node* root=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    int answer=-1;
    inorder(root,k,answer);
    cout<<answer<<'\n';
    return 0;
}