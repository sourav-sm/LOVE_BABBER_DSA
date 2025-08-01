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