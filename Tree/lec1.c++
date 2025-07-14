#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* left;
       Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
    int val;
    cin>>val;

    root=new Node(val);
    if(val==-1)return NULL;

    root->left=buildTree(root->left);
    root->right=buildTree(root->right);

    return root;  
}

//----------------DIFFERENT TYPES OF TRAVERSAL TECGNIQUES-------------------------------------------------------- 
//PREORDER
//NLR
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//POSTORDER
//LRN
void postOrder(Node* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//INORDER
//LNR
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

//LEVEL ORDER
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>ans;
    if(!root)return ans;
    queue<Node*>q;

    q.push(root);//initial state
    while(!q.empty()){
        int levelSize=q.size();
        vector<int>currLevel;
        for(int i=0;i<levelSize;i++){
            Node* node=q.front();
            q.pop();
            currLevel.push_back(node->data);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans.push_back(currLevel);
    }
    return ans;
}

//EASY PROBLEMS--------------------------------------------------------
//HEIGHT OF A TREE
int height(Node* root){
    if(!root)return 0;
    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

//DIAMETER OF A TREE

  int helper(Node* root,int& dia){
    if(!root)return 0;
    int leftheight=helper(root->left,dia);
    int rightheight=helper(root->right,dia);
    dia=max(dia,(leftheight+rightheight));
    return 1+max(leftheight,rightheight);
}
int diameterOfBinaryTree(Node* root) {
    int dia=0;
    helper(root,dia);
    return dia;
}




int main(){
    //10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1 
    Node* root=buildTree();  
}