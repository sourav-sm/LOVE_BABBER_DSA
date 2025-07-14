#include<bits/stdc++.h>
using namespace std;

/// NOTE THIS ARE DP PROBLEMS BUT FIRST WE HAVE SOLVE USING RECURSION AS HERE MIDE BE ALL TEST CASES NOT RUNS AS WE NOT DOING MEMORING HENCE
//TC WILL BE O(N^N)

//. Perfect Squares Recursion
//Given an integer n, return the least number of perfect square numbers that sum up to n.
//A perfect square is an integer that is the square of an integer. In other words, it is the product of an integer with itself. 
//For example, 1, 4, 9, and 16 are perfect squares, while 3 and 11 are not. */


class Solution {
public:
    //RECURSION
    int solve(int n){
        if(n==0)return 1;
        if(n<0)return 0;

        int ans=INT_MAX;
        int i=1;
        int end=sqrt(n);
        while(i<=end){
            int perfectSquare=i*i;
            int noOfPerfectSquare=1+solve(n-perfectSquare);
            ans=min(ans,noOfPerfectSquare);
            i++;
        }
        return ans;
    }
    int numSquares(int n) {
        return solve(n)-1;
    }
};

///------------------------------------------------------------------------------------------------



