#include<bitset>/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

//653. Two Sum IV - Input is a BST
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such 
//that their sum is equal to k, or false otherwise.

class Solution {
public:
    bool check(vector<int>&arr,int k){
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if((arr[i]+arr[j])==k)return true;
            else if((arr[i]+arr[j])>k)j--;
            else i++;
        }
        return false;
    }
    void storeInorder(TreeNode* root,vector<int>&arr){
        if(root==NULL)return;
        storeInorder(root->left,arr);
        arr.push_back(root->val);
        storeInorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        storeInorder(root,arr);
        bool ans=check(arr,k);
        return ans;
    }
};

///-------------------------------------------///-------------------------------------------
// 538. Convert BST to Greater Tree
//Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
//As a reminder, a binary search tree is a tree that satisfies these constraints:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


class Solution {
public:
    void storeInorder(TreeNode* root,vector<int>&arr){
        if(!root)return;
        storeInorder(root->left,arr);
        arr.push_back(root->val);
        storeInorder(root->right,arr);
    } 
    void updatevalsWithSum(vector<int>&arr){
        for(int i=arr.size()-2;i>=0;i--){
            arr[i]=arr[i]+arr[i+1];
        }
    }
    void updateTree(TreeNode* root,vector<int>&arr,int& index){
        if(!root)return;
        updateTree(root->left,arr,index);
        root->val=arr[index];
        index++;
        updateTree(root->right,arr,index);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int>arr;
        storeInorder(root,arr);
        updatevalsWithSum(arr);
        int index=0;
        updateTree(root,arr,index);
        return root;
    }
};

///-------------------------------------------///-------------------------------------------
 //METHOD-1
 class Solution {
public:
    void storeInArr(TreeNode* root,vector<int>&arr){
        if(!root)return;
        storeInArr(root->left,arr);
        arr.push_back(root->val);
        storeInArr(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        storeInArr(root,arr);
        return arr[k-1];
    }
};
//METHOD-2
//  WHAT IF INTERVIER ASK NOT TO STORE INORDER TRVAERSAL IN A ARR
class Solution {
public:
    void solve(TreeNode* root,int& count,int k,int& ans){
        if(!root)return;
        solve(root->left,count,k,ans);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        solve(root->right,count,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        solve(root,count,k,ans);
        return ans;
    }
};
///-------------------------------------------///-------------------------------------------
//235. Lowest Common Ancestor of a Binary Search Tree
//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
//descendants (where we allow a node to be a descendant of itself).”
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(p==root)return p;
        if(q==root)return q;
        
        //case1 if both of p and q on left side
        if(p->val<root->val && q->val<root->val){
            TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
            if(leftAns!=NULL){
                return leftAns;
            }
        }
        //case2 if both of p and q on right side
        if(p->val>root->val && q->val>root->val){
            TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
            if(rightAns!=NULL){
                return rightAns;
            }
        }
        //other case
        return root;
    }
};
///-------------------------------------------///-------------------------------------------

