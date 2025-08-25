/** 
LEETCODE 416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/

class Solution {
public:
    bool solveTabu(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));  

        for(int i=0;i<=n;i++){
            dp[i][0]=1;//THIS IS FOR THIS if(target==0)return 1; BASE CASE  
        }      

        for(int i=n-1;i>=0;i--){
            for(int t=0;t<=target;t++){
                bool exclude=dp[i+1][t];
                bool include=0;
                if(t-nums[i]>=0){
                    include=dp[i+1][t-nums[i]];
                }
                dp[i][t]=(include||exclude);
            }
        }
        return dp[0][target]; 
    }
    bool solveMemo(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        if(i>=nums.size())return 0;
        if(target==0)return 1;
        if(target<1)return 0;
        if(dp[i][target]!=-1)return dp[i][target];
        
        bool exclude=solveMemo(nums,target,i+1,dp);
        bool include=solveMemo(nums,target-nums[i],i+1,dp);

        dp[i][target]=(include||exclude);
        return (include||exclude);
    }
    bool solveRec(vector<int>&nums,int target,int i){
        if(i>=nums.size())return 0;
        if(target==0)return 1;
        if(target<1)return 0;
        
        bool include=solveRec(nums,target-nums[i],i+1);
        bool exclude=solveRec(nums,target,i+1);

        return (include||exclude);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        //if odd then not possible to break in part s 
        if(sum%2!=0)return false;
        int target=sum/2;
        int i=0;
        //recursion
        // return solveRec(nums,target,i);

        //MEMORIZATION---------
        //HERE WE HAVE TO NOTE THAT THIS IS 2D DP PROBLEM AS HERE 2 PARAMETER ARE CHANGING ONE IS i AND ANOTHER ONE IS target

        // int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solveMemo(nums,target,i,dp); 

        return solveTabu(nums,target);
    }
};