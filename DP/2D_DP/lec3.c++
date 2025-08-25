/**
 LEETCODE--300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.
 */

class Solution {
public:
    //memorization----------------------------------------------
    int solveMemo(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        //base case
        if(curr>=nums.size())return 0;
        //check ansis already exists or not
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];

        //main logic
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+solveMemo(nums,curr,curr+1,dp);
        }
        int exclude=solveMemo(nums,prev,curr+1,dp);//only curr is changing , prev is same as previous
        //store ans 
        dp[curr][prev+1]=max(include,exclude);
        return max(include,exclude);
    }
    //recursion----------------------------------------------
    int solveRec(vector<int>&nums,int prev,int curr){
        //base case
        if(curr>=nums.size())return 0;

        //main logic
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+solveRec(nums,curr,curr+1);
        }
        int exclude=solveRec(nums,prev,curr+1);//only curr is changing , prev is same as previous
        return max(include,exclude);
    } 
    // this 2d type dp as here both of prev and curr are changing
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        int n=nums.size();
     //  return solveRec(nums,prev,curr);   
     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     return solveMemo(nums,prev,curr,dp);
    }
};

/**
LEETCODE--1155. Number of Dice Rolls With Target Sum
You have n dice, and each dice has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    const int mod=1000000007;
    //Space optimization----------------------------------------------
    int solveSO(int n,int k,int target){
        //step1 initilise 
      vector<int>prev(target+1,0);
      vector<int>curr(target+1,0);
        //step 2 
        prev[0]=1;//base case
        //step 3 mainn temp looping and copy and paste and changing looping variables name accordingly 
        for(int a=1;a<=n;a++){
            for(int t=1;t<=target;t++){
                long long int ans=0;
                    for(int val=1;val<=k;val++){
                        long long int temp=0;
                        if(t-val>=0)temp=prev[t-val]%mod;
                        ans=(ans%mod + temp)%mod;
                    }
                 curr[t]=ans;
            }
            //shifting
            prev=curr;
        }
        //step 4
        return prev[target];
    }
    //Tabulation----------------------------------------------
    int solveTabu(int n,int k,int target){
        //step1 initilise dp
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        //NOTE ABOVE WE INITILISE WITH 0 BECAUSE IN ALL FOR 3 CASES IT WILL BE 0 AND ONLY N==0 AND TARGET==0 CASE IT WILL BE 1 
        //step 2 
        dp[0][0]=1;//base case
        //step 3 mainn temp looping and copy and paste and changing looping variables name accordingly 
        for(int a=1;a<=n;a++){
            for(int t=1;t<=target;t++){
                long long int ans=0;
                    for(int val=1;val<=k;val++){
                        long long int temp=0;
                        if(t-val>=0)temp=dp[a-1][t-val]%mod;
                        ans=(ans%mod + temp)%mod;
                    }
                 dp[n][t]=ans;
            }
        }
        //step 4
        return dp[n][target];
    }
    ///MEMORIZATION--------------------------------
    int solveMemo(int n,int k,int target,vector<vector<long long int>>&dp){
        //base casessss
        if(n==0 && target==0)return 1;
        if(n<0 || target<0)return 0;
        if(n==0 && target!=0)return 0;
        if(n!=0 && target==0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        
        long long int ans=0;
        for(int val=1;val<=k;val++){
            ans=(ans%mod + solveMemo(n-1,k,target-val,dp)%mod)%mod;
        }
        dp[n][target]=ans;
        return ans;
    }
    //RECURSION---------------------------------------
    int solveRec(int n,int k,int target){
        //base casessss
        if(n==0 && target==0)return 1;
        if(n<0 || target<0)return 0;
        if(n==0 && target!=0)return 0;
        if(n!=0 && target==0)return 0;
        
        int ans=0;
        for(int val=1;val<=k;val++){
            ans+=solveRec(n-1,k,target-val);
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        int mod=1e9+7;
        //  return solveRec(n,k,target);
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        return solveMemo(n,k,target,dp);
    }
};