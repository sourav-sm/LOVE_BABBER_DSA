#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

///------------------------------------------------------------------------------------------------
//Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.
class Solution {
public:
    int height(TreeNode* root){
        if(!root)return 0;
        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int leftHt=height(root->left);
        int rightHt=height(root->right);
        int absDiff=abs(leftHt-rightHt);
        if(absDiff>1)return false;
        else{
           int left=isBalanced(root->left);
           int right=isBalanced(root->right);
           if(left==true && right==true)return true;
           else return false;
        }
    }
};
///------------------------------------------------------------------------------------------------
//lca]\






















































+ \

///------------------------------------------------------------------------------------------------


//Path Sum

//Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
//A leaf is a node with no children.

class Solution {
public:
    bool solve(TreeNode* root, int targetSum,int sum){
        if(!root)return false;
        //if there is leaf node check sum with targetsum
        //base case
        sum+=root->val;

        if(root->left==NULL && root->right==NULL){
            return sum==targetSum;
        }
        //do one case
        
        int leftAns=solve(root->left,targetSum,sum);
        int rightAns=solve(root->right,targetSum,sum);

        return leftAns || rightAns;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=solve(root,targetSum,sum);
        return ans;
    }
};

///------------------------------------------------------------------------------------------------
vcṀ//Pa\++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++302pn]bth Sum II
//Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
//A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

class Solution {
public:
    void solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,int sum,vector<int>temp){
        if(!root)return ;
        //one case
        sum+=root->val;
        temp.push_back(root->val);
        //leaf node
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
                return;
            }
        }
        //recursion
        solve(root->left,targetSum,ans,sum,temp);
        solve(root->right,targetSum,ans,sum,temp);


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>>ans;
      int sum=0;
      vector<int>temp;
      solve(root,targetSum,ans,sum,temp);
      return ans;
    } 
};