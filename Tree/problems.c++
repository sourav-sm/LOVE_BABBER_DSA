#include<bits/stdc++.h>
using namespace std;

//Diagonal Traversal in a Binary Tree

//You are given a binary tree. Your task is to perform its diagonal traversal. In a diagonal traversal, nodes are grouped by their diagonals. The rules for forming the diagonals are:
//A node’s right child is on the same diagonal as the node.
//A node’s left child is on the next diagonal.
//You start from the root and add nodes from the topmost diagonal to the bottom diagonals, moving rightwards before moving downwards to the left.


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
    vector<int> diagonalTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process all nodes in the same diagonal
            while (node) {
                result.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                node = node->right;
            }
        }

        return result;
    }
};

///////////-------------------------------------------------------------------------------------------------------------------------
//TOP VIEW OF BINARY TREE

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> topNodes;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->val;
            }

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (const auto& pair : topNodes) {
            result.push_back(pair.second);
        }

        return result;
    }
};

///////////-------------------------------------------------------------------------------------------------------------------------
//BINARY TREE RIGHT SIDE VIEW 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();

                if(i==n-1){
                    ans.push_back(front->val);
                }
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
        return ans;
    }
};

///////////-------------------------------------------------------------------------------------------------------------------------
//ZIG-ZAG LEVEL ORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Placeholder for zigzag level order traversal
        vector<vector<int>>ans;
        if(!root)return ans;
        bool LtoR=true;//flag for checking the directions
        queue<TreeNode*>q;//as we are doing level order traversal;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>oneLevel(n);
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                int index=LtoR?i:n-i-1;//if ltor then i else n-i-1
                //as then we to push from back
                oneLevel[index]=front->val;
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            LtoR=!LtoR;//toggle the direction
            ans.push_back(oneLevel);
        }
        return ans;
    }
};


///////////-------------------------------------------------------------------------------------------------------------------------
//BOUNDARY TREE TAVERSAL

class Solution {
private:
    // Adds left boundary nodes (excluding leaf nodes)
    void addLeftBoundary(TreeNode* node, vector<int>& result) {
        while (node) {
            if (node->left || node->right) result.push_back(node->val); // Exclude leaf nodes
            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    // Adds all leaf nodes (left to right)
    void addLeaves(TreeNode* node, vector<int>& result) {
        if (!node) return;
        if (!node->left && !node->right) {
            result.push_back(node->val);
            return;
        }
        addLeaves(node->left, result);
        addLeaves(node->right, result);
    }

    // Adds right boundary nodes (excluding leaf nodes, in reverse order)
    void addRightBoundary(TreeNode* node, vector<int>& result) {
        vector<int> temp;
        while (node) {
            if (node->left || node->right) temp.push_back(node->val); // Exclude leaf nodes
            if (node->right) node = node->right;
            else node = node->left;
        }
        // Push right boundary in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        // Add root value if it's not a leaf node
        if (root->left || root->right) result.push_back(root->val);

        if (root->left) addLeftBoundary(root->left, result);
        addLeaves(root, result);
        if (root->right) addRightBoundary(root->right, result);

        return result;
    }
};