// 198. House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
class Solution {
public:
    //tabulation or bottom up approach-----------------------------
    int solveTabu(vector<int>&nums){
      //step1 dp array initilize
      int n=nums.size();
      vector<int>dp(n+1,-1);
      //anaslyse base case and fill up
      dp[n]=0;
      //step3 reverse the flow and copy paste
       for(int i=n-1;i>=0;i--){
        //handling boundary condition
        int temp=0;
        if(i+2<=n){
            temp=dp[i+2];
        }
        int include=nums[i]+temp;
        int exclude=dp[i+1];
        dp[i]=max(include,exclude);
       }
       //step 4 return ans
       return dp[0];//because we start 0 initilay for other approach

    }

    //memorization -------------------------------------------------------------
    int solveMemo(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size())return 0;
        
        //check ans is already exist or not
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int include=nums[i]+solveMemo(nums,i+2,dp);
        int exclude=solveMemo(nums,i+1,dp);
        ans=max(include,exclude);
        //storing ans

        dp[i]=ans;//here under [] the changing parameter always come
        return ans;
    }
    //Recursion---------------------------------------------------------
    int solveRec(vector<int>&nums,int i){
        if(i>=nums.size())return 0;
        int ans=0;
        int include=nums[i]+solveRec(nums,i+2);
        int exclude=solveRec(nums,i+1);
        ans=max(include,exclude);
        return ans;
    }
    
    int rob(vector<int>& nums) {
        // int i=0;
        // int ans=solveRec(nums,0);
        // return ans;
        
        //rec+memo+top down
        // int i=0;
        // int n=nums.size();
        // //1d dp as only i is changing  
        // vector<int>dp(n+1,-1);
        // int ans=solveMemo(nums,i,dp);
        // return ans;

        //tabuluation / top to bottom approach
        return solveTabu(nums);
    }
};

///-----------------------------------------------------------------
// 322. Coin Change
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

class Solution {
public: 
//tabulation top down
int solveTabu(vector<int>&coins,int amount){
    //step-1 dp array initlise
    int n=amount;//as amount is changing parameter
    vector<int>dp(n+1,INT_MAX);
    //analyse base case and fill up
    dp[0]=0;
    //reverse the flow
    for(int value=1;value<=amount;value++){
        int mini=INT_MAX;
          for(int i=0;i<coins.size();i++){
            if(coins[i]<=value){
            int tabuAns=dp[value-coins[i]];
            if(tabuAns!=INT_MAX){
                mini=min(mini,1+tabuAns);
            }
          }
        }
     dp[value]=mini;   
    }
    return dp[amount];
}
//rec+memo ---------------------------------------------------
int solveMemo(vector<int>&coins,int amount,vector<int>&dp){
    if(amount==0)return 0;
    if(dp[amount]!=-1)return dp[amount];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(coins[i]<=amount){
            int memoAns=solveMemo(coins,amount-coins[i],dp);
            if(memoAns!=INT_MAX){
                mini=min(mini,1+memoAns);
            }
        }
    }
    dp[amount]=mini;
    return mini;

}
//RECURSION-------------------------------------------------------------
    int solveRec(vector<int>&coins,int amount){
        //base case
        if(amount==0)return 0;
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int recAns=solveRec(coins,amount-coins[i]);
                if(recAns!=INT_MAX){
                    mini=min(mini,1+recAns);
                }
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
       //recursion
    //    int ans=solveRec(coins,amount);
    //    if(ans!=INT_MAX){
    //     return ans;
    //    }else{
    //     return -1;
    //    }

    //memorization
    //note n will be always the size of changing parameter
    // int n=amount;
    // vector<int>dp(n+1,-1);
    // int ans=solveMemo(coins,amount,dp);
    // if(ans==INT_MAX)return -1;
    // else return ans;

    //tabulation
    int ans=solveTabu(coins,amount);
    if(ans==INT_MAX)return -1;
    else return ans;
    }
};

