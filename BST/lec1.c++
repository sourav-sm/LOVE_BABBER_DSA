#include<vector>
class BST {
private:
   struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x){
            val=x;
            left=nullptr;
            right=nullptr;
        }
   };
   TreeNode* root;

   TreeNode* insert(TreeNode* root,int val){
    if(!root){
        root=new TreeNode(val);//for 1st time create a new node
    }
    if(val<root->val)root->left=insert(root->left,val);
    if(val>root->val)root->right=insert(root->right,val);
    return root;
   }
   
   TreeNode* search(TreeNode* root,int val){
    if(!root || root->val==val)return root;//not null and present
    if(val<root->val)return search(root->left,val);
    else return search(root->right,val);
   }

   TreeNode* deleteNode(TreeNode* root,int val){
    if(!root)return root;
    if(val<root->val)root->left=deleteNode(root->left,val);
    else if(val>root->val)root->right=deleteNode(root->right,val);
    else{
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        TreeNode* temp=minvalNode(root->right);
        root->val=temp->val;
        root->right=deleteNode(root->right,temp->val);
    }
    return root;
   }

   TreeNode* minvalNode(TreeNode* root){
    while(root && root->left)root=root->left;
    return root;
   }

   TreeNode* maxvalNode(TreeNode* root){
    while(root && root->right)root=root->right;
    return root;
   }

   void inorder(TreeNode* root,vector<int>&ans){
    if(!root)return ;//base case
    //LNR
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
   }
   void preorder(TreeNode* root,vector<int>&ans){
    if(!root)return ;
    //NLR
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
   }
   void postorder(TreeNode* root,vector<int>&ans){
     if(!root)return ;
     //LRN
     postorder(root->left,ans);
     postorder(root->right,ans);
     ans.push_back(root->val);
   }

public:
    BST() : root(nullptr) {
        // Constructor for initializing BST
    }
    
    void insert(int value) {
        // Insert a value in the BST
        root=insert(root,value);
    }
    
    bool search(int value) {
        // Search for a value in the BST
        return search(root,value)!=nullptr;
    }
    
    void deleteNode(int value) {
        // Delete a node from the BST
        deleteNode(root,value);
    }
    
    vector<int> inorderTraversal() {
        // Return inorder traversal as a vector
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
    
    vector<int> preorderTraversal() {
        // Return preorder traversal as a vector
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
    
    vector<int> postorderTraversal() {
        // Return postorder traversal as a vector
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};