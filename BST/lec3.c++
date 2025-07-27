//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

class Solution {
public:
    TreeNode* solve(vector<int>&nums,int s,int e){
        if(s>e)return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,s,mid-1);
        root->right=solve(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        TreeNode* ans=solve(nums,s,e);
        return ans;
    }   
};

//109. Convert Sorted List to Binary Search Tree
//Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

class Solution {
public:
    int getLen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    TreeNode* solve(ListNode* &head,int n){
        if(!head)return nullptr;
        if(n<=0)return nullptr;
        //L
        TreeNode* leftSubtree=solve(head,n/2);
        //N
        TreeNode* root=new TreeNode(head->val);
        root->left=leftSubtree;
        head=head->next;
        //R
        TreeNode* rightSubtree=solve(head,n-n/2-1);
        root->right=rightSubtree;

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len=getLen(head);
        TreeNode* ans=solve(head,len);
        return ans;
    }
};

///----------GOOOOOOOD HARDDDDDD QUESTIONNNNN MUST REVISEEEEEEE-------------------//
//LEETCODE 1363 Maximum Sum BST in Binary Tree

/** Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
/Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
**/

class Info{
    //make a class and specially this data is for null nodes
   public:
   int minVal=INT_MAX;
   int maxVal=INT_MIN;
   int sum=0;
   bool isBST=true;
};
class Solution {
public:
    Info solve(TreeNode* root,int& sum){
        if(root==NULL){
          Info temp;
          temp.minVal=INT_MAX;
          temp.maxVal=INT_MIN;
          temp.sum=0;
          temp.isBST=true;
          return temp;
        }
        //LNR
        Info leftAns=solve(root->left,sum);//l
        Info rightAns=solve(root->right,sum);//r
        //solving for n
        Info currAns;
        //checking all 4 conditions
        currAns.maxVal=max(root->val,max(leftAns.maxVal,rightAns.maxVal));
        currAns.minVal=min(root->val,min(leftAns.minVal,rightAns.minVal));
        currAns.sum=root->val+leftAns.sum+rightAns.sum;
        //check where BST or not
        if(root->val>leftAns.maxVal && root->val<rightAns.minVal && leftAns.isBST && rightAns.isBST ){
            currAns.isBST=true;
            sum=max(sum,currAns.sum);
        }else{
            currAns.isBST=false;
        }
        return currAns;
    }
    int maxSumBST(TreeNode* root) {
        int sum=0;
        Info ans=solve(root,sum);
        return sum;
    }
};

//GFG----Binary Tree to DLL
/**Difficulty: HardAccuracy: 53.36%Submissions: 163K+Points: 8Average Time: 60m
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
Note: h is the tree's height, and this space is used implicitly for the recursion stack.
**/

class Solution {
  public:
    void solve(Node*root,Node* &head,Node* &tail){
        if(root==NULL)return ;
        solve(root->left,head,tail);
        if(tail!=NULL){
            root->left=tail;
            tail->right=root;
            tail=root;//updating tail
        }else{
            head=root;
            tail=root;
        }
        solve(root->right,head,tail);
    }
    Node* bToDLL(Node* root) {
        // code here
        Node* head=NULL;
        Node* tail=NULL;
        solve(root,head,tail);
        return head;
    }
};