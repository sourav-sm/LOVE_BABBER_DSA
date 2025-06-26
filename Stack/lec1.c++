#include <bits/stdc++.h>
using namespace std;

class Stack{
  public:
    int *arr;
    int top;
    int size;
    
  Stack(int capacity){
      arr=new int(capacity);
      top=-1;
      size=capacity;
  }
  
  void push(int ele){
     //2 case possible either it will be overflow or normal push
     if(top==size-1){
         cout<<"overflow"<<endl;
     }else{
         top++;
         arr[top]=ele;
     }
  }
  
  void pop(){
      //2 case possible either underflow r normal pop
      if(top==-1){
          cout<<"underflow"<<endl;
      }else{
          top--;
      }
  }
  
  int topEle(){
      if(top==-1){
          cout<<"stack is empty"<<endl;
          return -1;
      }else{
        return arr[top];   
      }
  }
  
  bool isEmpty(){
      if(top==-1)return true;
      else return false;
  } 
  
  int getSize(){
      return top+1;
  }
};

int main()
{
    //creation
    Stack st(100);//int type stack with a capacity of 100
    st.push(2);
    st.push(5);
    st.push(6);
    
    cout<<st.getSize()<<endl;
    
    cout<<st.topEle()<<endl;
    
    st.pop();
    cout<<st.getSize()<<endl;
    
    cout<<st.isEmpty()<<endl;
    
    return 0;
}



/**********IMPLEMENTATION OF 2 STACKS USING ARRAY */

#include <bits/stdc++.h>
using namespace std;
class doubleStack{
  public:
     int *arr;
     int top1;
     int top2;
     int size;
     
     doubleStack(int capacity){
        arr=new int[capacity];
        top1=-1;
        size=capacity;
        top2=size;
     }
     
     void push1(int ele){
        if(top2-top1==1){
            cout<<"overflow"<<endl;
        }else{
            top1++;
            arr[top1]=ele;
        }
     }
     
     void push2(int ele){
        if(top2-top1==1){
            cout<<"overflow"<<endl;
        }else{
            top2--;
            arr[top2]=ele;
        }
     }
     
     void pop1(){
         if(top1==-1){
            cout<<"underflow"<<endl;
        }else{
            top1--;
        }
     }
     
     void pop2(){
        if(top2==size){
            cout<<"underflow"<<endl;
        }else{
            top2++;
        } 
     }
     
     int getTopEle1(){
        if(top1==-1){
            return -1;
            cout<<"stack 1 is empty";
        }else{
            return arr[top1];
        } 
     }
     
     int getTopEle2(){
        if(top2==size){
            return -1;
            cout<<"stack 2 is empty";
        }else{
            return arr[top2];
        } 
     }
     
     int size1(){
        return top1+1; 
     }
     
     int size2(){
        return size-top2;         
     }
     
     bool isEmpty1(){
        if(top1==-1)return true;
        else return false;
     }
     
     bool isEmpty2(){
        if(top2==size)return true;
        else return false;
     }
     
     void print(){
         for(int i=0;i<size;i++){
             cout<<arr[i]<<" ";
         }
         cout<<endl;
     }
};

int main()
{
    doubleStack dst(10);
    dst.push1(10);
    dst.push1(20);
    dst.push1(30);
    dst.push2(50);
    dst.push2(60);
    dst.push2(70);
    cout<<dst.getTopEle1()<<endl;
    cout<<dst.getTopEle2()<<endl;
    dst.print();
    return 0;
}



//***GIVEN A STACK WITH SOME VALUES , NOW ANOTHER VALUE VAL IS GIVEN INSERT IT AT BOTTOM */
#include <bits/stdc++.h>
using namespace std;
void insertatBottom(stack<int>&st,int val){
    //basecase
    if(st.empty()){
        st.push(val);
        return;
    }
    //do 1 thing rest is done by recursion
    int topval=st.top();//store top value;
    st.pop();//pop that value
    insertatBottom(st,val);// recursion
    st.push(topval);//backtrack
}


int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    int val=100;
    insertatBottom(st,val);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}



//REVERSE STACK 
#include <bits/stdc++.h>
using namespace std;
void insertatBottom(stack<int>&st,int val){
    //basecase
    if(st.empty()){
        st.push(val);
        return;
    }
    //do 1 thing rest is done by recursion
    int topval=st.top();//store top value;
    st.pop();//pop that value
    insertatBottom(st,val);// recursion
    st.push(topval);//backtrack
}

void reverseStack(stack<int>&st){
    //base case
    if(st.empty())return;
    
    //do 1st step rest is done by recursion
    int topval=st.top();
    st.pop();
    reverseStack(st);
    insertatBottom(st,topval);
}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    reverseStack(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}