/**302. Merge Two Binary Max Heap
You are given two binary max-heaps represented by their root nodes. Your task is to merge these two heaps into a single binary max-heap. A binary max-heap is a complete binary tree where each node's value is greater than or equal to the values of its children. The resulting merged heap should maintain this max-heap property. */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
   void heapify(vector<int>& c,int i, int n){
     while(true){
        int left=2*i+1;
        int right=2*i+2;
        int swapIndex=i;
        if(left<n && c[left]>c[i]){
            swapIndex=left;
        }
        if(right<n && c[right]>c[swapIndex]){
            swapIndex=right;
        }
        if(swapIndex==i){
            break;
        }
        swap(c[i],c[swapIndex]);
        i=swapIndex;
     }
   }
    vector<int> mergeHeaps(vector<int>& heap1, vector<int>& heap2) {
        //step 1 merge two heapvector
        vector<int>c(heap1.begin(),heap1.end());
        c.insert(c.end(),heap2.begin(),heap2.end());
        //step2 heapify
        for(int i=(c.size()/2)-1;i>=0;i--){
            heapify(c,i,c.size());
        }
        return c;
    }
};

/**301. Check if Binary Tree is Heap or Not
Given the root of a binary tree, your task is to determine if this tree satisfies the properties of a max-heap. A binary tree qualifies as a max-heap if it meets the following requirements:
Complete Binary Tree: All levels of the tree must be fully filled except possibly the last level, which should be filled from left to right.
Max-Heap Property: The value of each node must be greater than or equal to the values of its children.
Your goal is to implement a function that returns true if the binary tree satisfies the max-heap properties; otherwise, it should return false.
 */

class Solution {
private:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(TreeNode* root, int index, int nodeCount) {
        if (!root) return true;
        if (index >= nodeCount) return false;
        return isComplete(root->left, 2 * index + 1, nodeCount) &&
               isComplete(root->right, 2 * index + 2, nodeCount);
    }

    bool isMaxHeap(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->val < root->left->val) return false;
        if (root->right && root->val < root->right->val) return false;
        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }

public:
    bool isHeap(TreeNode* root) {
        int nodeCount = countNodes(root);
        return isComplete(root, 0, nodeCount) && isMaxHeap(root);
    }
};