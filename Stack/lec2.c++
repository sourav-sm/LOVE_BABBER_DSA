


///CHECK IF GIVEN STACK IS SORTED OR NOT 
#include <bits/stdc++.h>
using namespace std;
bool isSorted(stack<int>&st,int prev){
    //base case
    if(st.empty())return true;
    
    //do 1st case and rest is handled by recurssion 
    int next=st.top();
    if(next<prev){
        return false;//not sorted
    }else{
        prev=next;
        st.pop();
        return isSorted(st,prev);
    }
}


int main()
{
    stack<int>st;
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);
    
    int prev=INT_MIN;
    cout<<isSorted(st,prev)<<endl;

    return 0;
}

//INSERT SORTED
#include <bits/stdc++.h>
using namespace std; 

void insertSorted(stack<int>&st,int value){
    //base case if the stack is empty then directly push the element
    if(st.empty()){
        st.push(value);
        return;
    }
    
    //1st case handle it rest is done by recursion
    if(value<=st.top()){
        st.push(value);
        return;
    }else{
        int topValue=st.top();
        st.pop();
        insertSorted(st,value);//recurssion
        st.push(topValue);//backtrack
    }
}

 void print(stack<int>&st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
  }

int main()
{
    stack<int>st;
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);
    
    int value=25;
    insertSorted(st,value);
    
    print(st);
    return 0;
}


//CHECK VALID PARENTHESIS 
//MOST IMPORTANT PROBLEM----------------------

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            //opening brackets
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            //closing brackeets
            else{
                //1ST CHECK THE STACK IS EMPTY OR NOT
            if(st.empty())return false;
            //here 2 case possible either they match or nomatch
            //no match
            if(ch==')' && st.top()!='(')return false;
            else if(ch=='}' && st.top()!='{')return false;
            else if(ch==']' && st.top()!='[')return false;
            //match case
            else st.pop();
            }
        }
        //REMEBER THIS CONDITON TO CHECK WETHER THE STACK IS EMPTY OR NOT 
        return st.empty();//it means if(st.empty()){
        //     //it means sare brackets cancel out ho gaya hai 
        //     return true;
        // }else{
        //     //cancel out ho gaye but still some brackets are still left in the stack 
        //     return false;
        // }
    }
};

//Expression contains redundant bracket or not
//GFG

class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='+' ||ch=='-' ||ch=='*'|| ch=='/'){
                st.push(ch);
            }else if(ch==')'){//here we need to write if because s[i]can be innumberx
                bool operatorFound=false;
                while(!st.empty() && st.top()!='('){
                    char value=st.top();
                    if(value=='+'||value=='-'||value=='*'||value=='/')operatorFound=true;
                    st.pop();  
                }
                if(operatorFound==false)return true;
                else st.pop();
            }
        }
        return false;
    }
};
