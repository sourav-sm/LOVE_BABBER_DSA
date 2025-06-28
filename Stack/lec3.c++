//FIND NEXT SMALLER ELEMENT
#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>solve(vector<int>&arr){
   stack<int>st;
   st.push(-1);//initially
   vector<int>ans;
   
   for(int i=arr.size()-1;i>=0;i--){
       int element=arr[i];
       
       while(st.top()>=element){
           st.pop();
       }
       //ruk jao
       ans.push_back(st.top());
       st.push(element);//for next elements
   }    
   return ans;
}


int main()
{
    vector<int>arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    
    vector<int>ans;
    ans=solve(arr);
 //HERE WE NEED TO REVERSE AS WE ARE TARVERSING FROM RIGHT END 
    reverse(ans.begin(),ans.end());
    
    for(auto it:ans){
        cout<<it<<" ";
    }
 
    return 0;
}


//PREV SMALLER ELEMENT
#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>solve(vector<int>&arr){
   stack<int>st;
   st.push(-1);//initially
   vector<int>ans;
   
   for(int i=0;i<arr.size();i++){
       int element=arr[i];
       
       while(st.top()>=element){
           st.pop();
       }
       //ruk jao
       ans.push_back(st.top());
       st.push(element);//for next elements
   }    
   return ans;
}


int main()
{
    vector<int>arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(3);
    
    vector<int>ans;
    ans=solve(arr);
    
    for(auto it:ans){
        cout<<it<<" ";
    }
 
    return 0;
}

// 84. Largest Rectangle in Histogram
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

class Solution {
public:
     void nextSmallerElements(vector<int>& heights,vector<int>&nextSmallerAns){
        stack<int>st;
        st.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            int element=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=element){
                st.pop();
            }
            //ruk jao
            nextSmallerAns.push_back(st.top());
            st.push(i);
        }
     }

     void prevSmallerElements(vector<int>& heights,vector<int>&prevSmallerAns){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            int element=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=element){
                st.pop();
            }
            //ruk jao
            prevSmallerAns.push_back(st.top());
            st.push(i);
        }
     }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextSmallerAns;
        vector<int>prevSmallerAns;
        nextSmallerElements(heights,nextSmallerAns);
        reverse(nextSmallerAns.begin(),nextSmallerAns.end());
        for(int i=0;i<nextSmallerAns.size();i++){
            if(nextSmallerAns[i]==-1){
                nextSmallerAns[i]=nextSmallerAns.size();
            }
        }
        
        prevSmallerElements(heights,prevSmallerAns);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int next=nextSmallerAns[i];
            int prev=prevSmallerAns[i];
            int dia=next-prev-1;
            int ht=heights[i];
            int area=dia*ht;
            maxArea=max(maxArea,area);
        }
       return maxArea; 
    }
};

