/**LEETCODE 1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
**/
class Solution {
public:
    //-----TABULATION--------
    int solveTabu(string a,string b){
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        dp[n][m]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                    int ans=0;
                    if(a[i]==b[j]){
                        ans=1+dp[i+1][j+1];
                    }else{
                        ans=max(dp[i+1][j],dp[i][j+1]);
                    }
                    dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

    //-----MEMORIZARION--------
    //NOTE HERE WE PASS a AND b in PASS BY RFERENCE SO THAT 47 TEST CASES CAN PASSED 
    int solveMemo(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.size()||j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveMemo(a,b,i+1,j+1,dp);
        }else{
            ans=max(solveMemo(a,b,i+1,j,dp),solveMemo(a,b,i,j+1,dp));
        }
        dp[i][j]=ans;
        return ans;
    }
    //-----RECURSION--------
    int solveRec(string a,string b,int i,int j){
        if(i>=a.size()||j>=b.size())return 0;
        
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveRec(a,b,i+1,j+1);
        }else{
            ans=max(solveRec(a,b,i+1,j),solveRec(a,b,i,j+1));
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        // return solveRec(text1,text2,i,j);

        //----MEMORIZATION---
        //this is 2d dp problem as here 2 parameter i and j is changing
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveMemo(text1,text2,i,j,dp);

        //---------TABULATION------------
        return solveTabu(text1,text2);
    }
};

 