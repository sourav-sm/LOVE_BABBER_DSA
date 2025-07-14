#include<bits/stdc++.h>
using namespace std;

// . Reverse String [Using Recursion]
class Solution {
public:
     void solve(vector<char>& s,int st,int lt){
        if(st>=lt)return ;
        swap(s[st],s[lt]);
        return solve(s,st+1,lt-1);

     }
     vector<char> reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
        return s;
    }
};

///IMPORTANT ONE PRINT ALL SUBSEQUENCE------
// /-------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
class Solution {
public:
    void solve(string s,int index,string output,vector<string>&ans){
        //base case
        if(index>=s.length()){
            ans.push_back(output);
            return;
        }
        //do one case rest is handel by recursion
        //include
        // solve(s,index+1,output+s[index],ans);//wrong way to include
        output.push_back(s[index]);//bettter way to include
        solve(s,index+1,output,ans);
        //exclude
        output.pop_back();//ideal way to pop back
        solve(s,index+1,output,ans);
        // solve(s,index+1,output,ans);//wrong way
    }
    vector<string> generateAllSubsequences(string s) {
       vector<string>ans;
       string output="";
       int index=0;
    
        solve(s,index,output,ans);
        //sort the ans before sending back
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// /-------------------------------------------------------------------------------------------
//HOUSE ROVER
#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>& nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        //include
        int inludeAns= nums[index]+solve(nums,index+2);
        //exclude
        int excludeAns= solve(nums,index+1);
        //return max of includeans and exlcudeans
        int finalAns=max(inludeAns,excludeAns);

        return finalAns;
    }
    int rob(vector<int>& nums) {
        int money=0;
        
        return solve(nums,0);
    }
};



// /-------------------------------------------------------------------------------------------
//CHECK ARRAY IS SORTED OR NOT USING RECURSION
bool checkArraySortedRecursive(vector<int>arr,int index){
    if(index==0)return true;
    
    if(arr[index]<arr[index-1])return false;
    
    return checkArraySortedRecursive(arr,index-1);
    
}

// /-------------------------------------------------------------------------------------------
//Valid Palindrome Using Recursion
class Solution {
public:
    bool solve(string& s,int st,int en){
        //base case
        if(st>en)return true;
        
        //skip non-alphanumeric char
        if(!isalnum(s[st]))return solve(s,st+1,en);
        if(!isalnum(s[en]))return solve(s,st,en-1);

        //recursive case
        if(tolower(s[st])!=tolower(s[en]))return false;
        return solve(s,st+1,en-1);
    }
    bool isPalindrome(string s) {
        // User will add logic here
       return solve(s,0,s.length()-1);
    }
};

// /-------------------------------------------------------------------------------------------
//Print All Substrings of a String Using Recursion

class Solution {
public:
    void solve(string s,int st,int en,vector<string>& ans){
        //base case
        if(en==s.length()+1)return;

        if(st==en){
            solve(s,0,en+1,ans);
            return;
        }
        ans.push_back(s.substr(st,en-st));
        solve(s,st+1,en,ans);
    }
    vector<string>printAllSubstrings(string s) {
        vector<string>ans;
        solve(s,0,1,ans);
        return ans;
    }
};

// /-------------------------------------------------------------------------------------------
//Add Strings Using Recursion
class Solution {
public:
    string solve(string num1, int i,string num2,int j,int carry){
        if(i<0 && j<0){
            if(carry!=0)return string(1,carry+'0');
            return "";
        }
        int n1=(i>=0?num1[i]:'0')-'0';
        int n2=(j>=0?num2[j]:'0')-'0';
        int sum=n1+n2+carry;
        int digit=sum%10;
        carry=sum/10;
        string ans="";
        ans.push_back(digit+'0');

        //recursion call
        ans+=solve(num1,i-1,num2,j-1,carry);
        return ans;

    }
    string addStrings(string num1, string num2) {
        // User will implement the logic here
        int carry=0;
        string ans=solve(num1,num1.size()-1,num2,num2.size()-1,carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// /-------------------------------------------------------------------------------------------
//Remove All Occurrences of a Substring Using Recursion
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Logic to be implemented by the user
        while(s.find(part)!=string::npos){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};

// /-------------------------------------------------------------------------------------------

// Best Time to Buy and Sell Stock Using Recursion
class Solution {
public:
    void solve(vector<int>& prices,int& minPrice,int& maxProfit,int i){
        //base case
        if(i==prices.size())return;
        
        //one case
        if(prices[i]<minPrice)minPrice=prices[i];
        int currProfit=prices[i]-minPrice;
        if(currProfit>maxProfit)maxProfit=currProfit;
        
        //recursion
        solve(prices,minPrice,maxProfit,i+1);
    }
    int maxProfit(vector<int>& prices) {
        // Placeholder logic for maximum profit calculation
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        solve(prices,minPrice,maxProfit,0);
        return maxProfit;
    }
};
// /-------------------------------------------------------------------------------------------
//factorial of a number 
int factorial(int n) {
    // Base case and recursive logic to be implemented
    if(n==0 || n==1)return 1;
    return n*factorial(n-1);
}
// /-------------------------------------------------------------------------------------------
// Compute Power of a Number Recursively
int powerRecursive(int base, int exponent) {
    // Implement this function
    if(exponent==0)return 1;
    if(exponent==1)return base;
    int ans=1;
    ans*=base;
    return ans*powerRecursive(base,exponent-1);
}

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------

// /-------------------------------------------------------------------------------------------


