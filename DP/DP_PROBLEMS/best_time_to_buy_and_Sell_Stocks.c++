/**Best Time to Buy and Sell Stock-I
You are provided with a list called prices, where each element prices[i] denotes the price of a stock on the ith day. Your task is to find the best day to buy the stock and another, later day to sell the stock in order to maximize your profit. Keep in mind that you can only complete one transaction (buy and sell one stock), and you cannot sell a stock before you buy one.
If it is not possible to achieve any profit, return 0. */

class Solution {
public:
    int solveMemo(vector<int>& prices,int i,int minPrice,int& maxProfit,vector<int>&dp){
        if(i>=prices.size())return 0;
        if(dp[i]!=-1)return dp[i];

        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
        
        int recAns=solveMemo(prices,i+1,minPrice,maxProfit,dp);
        dp[i]=max(recAns,maxProfit);
        return max(recAns,maxProfit);
    }
    int solveRec(vector<int>& prices,int i,int minPrice,int& maxProfit){
        if(i>=prices.size())return 0;
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
        int recAns=solveRec(prices,i+1,minPrice,maxProfit);
        return max(recAns,maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        // Placeholder logic for maximum profit calculation
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;

        ///------ITETRATIVE APPROACH---------------
        // for(int price:prices){
        //     minPrice=min(minPrice,price);
        //     maxProfit=max(maxProfit,price-minPrice);
        // }
        // return maxProfit;

        ///------RECURSIVE APPROACH---------------
        // return solveRec(prices,0,minPrice,maxProfit);
        
        ///------MEMORIZATION APPROACH---------------
        int n=prices.size();
        vector<int>dp(n+1,-1);
        return solveMemo(prices,0,minPrice,maxProfit,dp);
        ///------ITETRATIVE APPROACH---------------
        ///------ITETRATIVE APPROACH---------------
    }
};

//------------------------------------------------------------

/**Best Time to Buy and Sell Stock II
In this problem, you are given an array prices where prices[i] represents the price of a stock on the i-th day. The objective is to determine the maximum profit you can achieve by buying and selling the stock. You are allowed to make multiple transactions (buy one and sell one share of the stock multiple times). However, you must sell the stock before you can buy again, and you can only hold one share of the stock at any given time. Buying and selling actions can happen on the same day, meaning you can buy in the morning and sell in the afternoon.
For each day, you have the choice to buy, sell, or do nothing. The challenge is to identify the sequence of days that will yield the highest possible profit. */

class Solution {
public:
    int solveMemo(vector<int>& prices,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];

        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveMemo(prices,i+1,0,dp);
            int skipProfit=solveMemo(prices,i+1,1,dp);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveMemo(prices,i+1,1,dp);
            int skipProfit=solveMemo(prices,i+1,0,dp);
            profit=max(skipProfit,sellProfit);
        }      
        dp[i][buy]=profit;
        return profit;  
    }
    int solveRec(vector<int>& prices,int i,int buy){
        if(i>=prices.size())return 0;
        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveRec(prices,i+1,0);
            int skipProfit=solveRec(prices,i+1,1);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveRec(prices,i+1,1);
            int skipProfit=solveRec(prices,i+1,0);
            profit=max(skipProfit,sellProfit);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        // Placeholder logic for calculating maximum profit
        ///here we have 3 option either buy , sell or ignore that day
        //note first we have to buy before sell
        //i.e we will try all possible bruteforce way using recursion
        //return solveRec(prices,0,true);//prices array,i,should we buy or not

        //-----------------MEMORIZATION----------------
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solveMemo(prices,0,true,dp);
    }
};

//------------------------------------------------------------
/**Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] denotes the price of a stock on the i-th day. You need to maximize your profit by making at most two transactions. Each transaction consists of buying on one day and selling on another later day. Importantly, you must sell the stock before buying again. */

class Solution {
public:
    int solveMemo(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() ||limit==0)return 0;
        if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];

        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveMemo(prices,i+1,0,limit,dp);
            int skipProfit=solveMemo(prices,i+1,1,limit,dp);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveMemo(prices,i+1,1,limit-1,dp);
            int skipProfit=solveMemo(prices,i+1,0,limit,dp);
            profit=max(sellProfit,skipProfit);
        }
        dp[i][buy][limit]=profit;
        return profit;
    }
    int solveRec(vector<int>& prices,int i,int buy,int limit){
        if(i>=prices.size() ||limit==0)return 0;
        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveRec(prices,i+1,0,limit);
            int skipProfit=solveRec(prices,i+1,1,limit);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveRec(prices,i+1,1,limit-1);
            int skipProfit=solveRec(prices,i+1,0,limit);
            profit=max(sellProfit,skipProfit);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        // Placeholder logic for maximum profit with at most two transactions
        //THIS PROBLEM IS SAME AS BUT STOCK AND SELL2 
        //JUST DIFFERENCE IS HERE THE MAXIMUM LIMIT IS 2 
        int i=0;
        int limit=2;
        // return solveRec(prices,i,true,limit);

        //-----MEMORIZATION------------
        //HRERE 3 CHANGING PARAMTER i,buy,limit
        // hence this is 3d dp
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMemo(prices,i,true,limit,dp);
    }
};

//------------------------------------------------------------
/**Best Time to Buy and Sell Stock IV
You are given an array prices where prices[i] denotes the price of a stock on the i-th day. Additionally, you are given an integer k representing the maximum number of transactions you can complete.
A transaction is a sequence of actions involving buying and then selling stocks on different days, ensuring that you sell your current stock before buying a new one.
Your objective is to calculate the maximum profit you can gain by performing up to k transactions.
**/

class Solution {
public:
    int solveMemo(vector<int>&prices,int i,int buy,int k,vector<vector<vector<int>>>&dp){
        //base case
        if(i>=prices.size() || k==0)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];

        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveMemo(prices,i+1,0,k,dp);
            int skipProfit=solveMemo(prices,i+1,1,k,dp);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveMemo(prices,i+1,1,k-1,dp);//complete tranj hence k-1
            int skipProfit=solveMemo(prices,i+1,0,k,dp);
            profit=max(sellProfit,skipProfit);
        }
        dp[i][buy][k]=profit;
        return profit;
    }
    int solveRec(vector<int>&prices,int i,int buy,int k){
        //base case
        if(i>=prices.size() || k==0)return 0;

        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveRec(prices,i+1,0,k);
            int skipProfit=solveRec(prices,i+1,1,k);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveRec(prices,i+1,1,k-1);//complete tranj hence k-1
            int skipProfit=solveRec(prices,i+1,0,k);
            profit=max(sellProfit,skipProfit);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
       //THIS PROBLEM IS SAME AS BUY_AND_SELL_III JUST IN PLACE OF LIMIT OF WE HAVE TO PASS K
        int i=0;
        //return solveRec(prices,i,true,k);//true means we can buy

        //----------THIS IS 3D DP PROBLEM AS HERE 3 CHANGING PARAMETER i,buy,k
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveMemo(prices,i,true,k,dp);
    }
};