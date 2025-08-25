/**
 * 
 GFG.  Painting the Fence
Difficulty: MediumAccuracy: 32.89%Submissions: 122K+Points: 4Average Time: 40m
Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer. */

class Solution {
  public:
    int solveTabu(int n,int k){
        vector<int>dp(n+1,-1);
        dp[1]=k;
        dp[2]=k*k;
        for(int a=3;a<=n;a++){
            dp[a]=(dp[a-2]+dp[a-1])*(k-1);
        }
         return dp[n];
    }
    int solveMemo(int n,int k,vector<int>&dp){
        if(n==1)return k;
        if(n==2)return k*k;
        if(dp[n]!=-1)return dp[n];
        int ans=(solveMemo(n-2,k,dp)+solveMemo(n-1,k,dp))*(k-1);
        dp[n]=ans;
        return ans;
    }
    //recursion----------------------------------------------
    int solveRec(int n,int k){
        if(n==1)return k;
        if(n==2)return k*k;
        int ans=(solveRec(n-2,k)+solveRec(n-1,k))*(k-1);
        return ans;
    }
    int countWays(int n, int k) {
        // code here
        //recursion----------------------------------------------
        // return solveRec(n,k);
        
        //--------------MEMORIZATION-------------------
        
        // vector<int>dp(n+1,-1);
        // return solveMemo(n,k,dp);
        
        //------TABULATION-----------------
        return solveTabu(n,k);
    }
};

/**** 
GFG - 0 - 1 Knapsack Problem
Difficulty: MediumAccuracy: 31.76%Submissions: 522K+Points: 4
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 
Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity */



class Solution {
  public:
    //-----TABULATION---------------------------
    int solveTabu(int cap,vector<int>&val,vector<int>&wt){
        int n=wt.size();
        vector<vector<int>>dp(cap+1,vector<int>(n+1,0));
        //looping
        //first loop is for capacity
        for(int c=0;c<=cap;c++){
            //second loop for i
            for(int i=n-1;i>=0;i--){
                int include=0;
                if(wt[i]<=c){
                    include=val[i]+dp[c-wt[i]][i+1];
                }
                int exclude=dp[c][i+1];
                dp[c][i]=max(include,exclude);
            }
        }
        return dp[cap][0];
    }
    //----MEMORIZATION---------------------------
    int solveMemo(int cap,vector<int>&val,vector<int>&wt,int i,vector<vector<int>>&dp){
        if(i>=wt.size())return 0;
        if(dp[cap][i]!=-1)return dp[cap][i];
        int include=0;
        if(wt[i]<=cap){
            include=val[i]+solveMemo(cap-wt[i],val,wt,i+1,dp);
        }
        int exclude=solveMemo(cap,val,wt,i+1,dp);
        dp[cap][i]=max(include,exclude);
        return max(include,exclude);
    }
  //recursion----------------------------------------------
    int solveRec(int cap,vector<int>&val,vector<int>&wt,int i){
        if(i>=wt.size())return 0;
        int include=0;
        if(wt[i]<=cap){
            include=val[i]+solveRec(cap-wt[i],val,wt,i+1);
        }
        int exclude=solveRec(cap,val,wt,i+1);
        return max(include,exclude);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int i=0;//for tracking index;
        // return solveRec(W,val,wt,i);
        
        //-----MEMORIZATION----------------
        // int n=wt.size();
        // vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        // return solveMemo(W,val,wt,i,dp);
        
        //------TABULATION------------------
        return solveTabu(W,val,wt);
    }
};