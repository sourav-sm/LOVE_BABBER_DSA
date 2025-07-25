//Roti Prata Problem
/**You are given n pratas that need to be cooked by l cooks. Each cook has a rank R which determines how quickly they can cook pratas.
A cook with rank R takes R minutes to cook the first prata, 2R minutes for the second, 3R minutes for the third, and so on.
Each cook can only prepare one prata at a time.
Your task is to determine the minimum amount of time required to cook all n pratas.
**/

class Solution {
public:
    bool isPossible(int p, int cook[], int n, int mid) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            int time = mid;
            int perpratas = cook[i]; // time taken to cook each pratas by ith cook
            while (time > 0) {
                time -= perpratas;
                if (time >= 0) {
                    c += 1;
                    perpratas += cook[i];
                }
            }
            cnt += c;
            if (cnt >= p)
                return true;
        }
        return false;
    }

    int minTimeToCookPratas(int p, int cook[], int n) {
        int s = 0, e = 10000007;
        int mid, ans = -1;

        while (s <= e) {
            mid = (s + e) / 2;
            if (isPossible(p, cook, n, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

//-----------------------------------------------------------------------------------------
//453. Find Quotient Without Using Division and Modulus Operators
/******
 You have been given two integers, dividend and divisor, and your task is to compute the quotient resulting from dividing dividend by divisor without using the built-in division (/) or modulus (%) operators. The result should be the quotient of the division truncated towards zero, which means the fractional part of the result should be discarded.
While implementing the function, handle the case of division by zero by returning the maximum positive integer value (INT_MAX).
****/


#include<limits.h>
long long int solve(long long int dividend,long long int divisor){
    long long int s=0,e=dividend;
    long long int ans=-1;
    while(s<=e){
        long long int mid=(s+e)/2;
        long long product=mid*divisor;
        if(product==dividend){
            return mid;
        }
        else if(product>dividend){
            e=mid-1;
        }else{
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

long long int findQuotient(int dividend, int divisor) {
    // The user will implement this method
    if(divisor==0)return INT_MAX;
    long long int ans=solve(abs((long long int)dividend),abs((long long int)divisor));
    if((dividend>0 && divisor>0)||(dividend<0 && divisor<0))return ans;
    else return (0-ans);

    return 0;
}