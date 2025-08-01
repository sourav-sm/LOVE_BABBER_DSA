/**LEETCODE 215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting? */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();

    }
};


/**
 * GFG 
 * Minimum Cost of ropes
Difficulty: EasyAccuracy: 42.73%Submissions: 248K+Points: 2
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.  */

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        int totalCost=0;
        while(pq.size()>1){
            int ele1=pq.top();
            pq.pop();
            int ele2=pq.top();
            pq.pop();
            int sum=ele1+ele2;
            pq.push(sum);
            totalCost+=sum;
        }
        return totalCost;
    }
};

/**958. Check Completeness of a Binary Tree
Given the root of a binary tree, determine if it is a complete binary tree.
In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool nullFound=false;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                nullFound=true;
            }else{
                if(nullFound==true){
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};