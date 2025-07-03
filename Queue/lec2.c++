#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseQueue(queue<int>&q){
  stack<int>st;
    while (!q.empty())
  {
    st.push(q.front());
    q.pop();
  }
    while (!st.empty())
  {
    q.push(st.top());
     st.pop();
  }
  
}

//3rd QUESTION REVERSE K GROUPS
void reverseKGroups(queue<int>&q,int k,int unUsedCount){
    if(unUsedCount>=k){
        stack<int>st;
        for(int i=0;i<k;i++){
            int ele=q.front();
            q.pop();
            st.push(ele);
        }
        for(int i=0;i<k;i++){
            int ele=st.top();
            st.pop();
            q.push(ele);
        }
        reverseKGroups(q,k,unUsedCount-k);
    }else{
        for(int i=0;i<unUsedCount;i++){
            int ele=q.front();
            q.pop();
            q.push(ele);
        }
    }
}
void printqueue(queue<int>&q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);
    printqueue(q);
}