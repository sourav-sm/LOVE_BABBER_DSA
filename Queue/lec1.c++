#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"queue is not empty"<<endl;
    }
    
    cout<<q.front()<<endl;
    
    cout<<q.back()<<endl;
    
    q.pop();
    
    cout<<q.size()<<endl;
    

    return 0;
}

/******DEQUE************************************** */
#include<iostream>
#include<queue>
using namespace std;

int main(){
  deque<int>dq;
  
  dq.push_front(5);
  dq.push_front(10);
  dq.push_front(20);
  if(dq.empty()){
      cout<<"dq is empty"<<endl;
  }else{
      cout<<"dq is not empty"<<endl;
  }
  
  dq.pop_back();
  dq.pop_front();
  
  cout<<dq.size()<<endl;
}


//BUILD YOUR OWN QUEUE
#include<iostream>
using namespace std;

class Queue{
   int *arr;
   int size;
   int front;
   int rear;
   public:
   
   Queue(int capacity){
       arr =new int[capacity];
       size=capacity;
       front=-1;
       rear=-1;
   }
   
   void push(int val){
       //3 possible case
       //case1 empty
       //case3 overflow
       if(rear==size-1){
           cout<<"overflow"<<endl;
           return;
       }
       if(rear==-1 && front==-1){
           rear++;
           front++;
           arr[rear]=val;
       }else{
         //case2 normal case3
         rear++;
         arr[rear]=val;
       }
   }
   
   void pop(){
       //3 possible case
       //case1 Queue is empty
       if(front==-1 && rear==-1){
           cout<<"underflow"<<endl;
           return;
       }
       //case2 only 1 element is present
       if(front==rear){
           arr[front]=-1;
           front=-1;
           rear=-1;
       }else{
       //case3 normal case
          arr[front]=-1;
          front++;
       }
   }
   
   bool checkEmpty(){
       if(front==-1 && rear==-1){
           return true;
       }else{
           return false;
       }
   }
   
   int getSize(){
       if(front==-1 && rear==-1)return 0;
       else{
        return rear-front+1;   
       }
   }
   
   int getFrontEle(){
       if(front==-1){
           cout<<"there is not front element"<<endl;
           return -1;
       }else{
           return arr[front];
       }
   }
   
   int getRearEle(){
       if(front==-1){
           cout<<"there is not front element"<<endl;
           return -1;
       }else{
           return arr[rear];
       }
   }
};

int main(){
    Queue q(100);
    q.push(5);
    q.push(15);
    cout<<q.getSize()<<endl;
    cout<<q.getRearEle()<<endl;
    cout<<q.getFrontEle()<<endl;
    q.pop();
    q.pop();
    cout<<q.checkEmpty()<<endl;
}

//CIRCULAR QUEUE**********************************************

#include<iostream>
using namespace std;

class circularQueue{
   int *arr;
   int size;
   int front;
   int rear;
   public:
   
   circularQueue(int capacity){
       arr =new int[capacity];
       size=capacity;
       front=-1;
       rear=-1;
   }
   
   void push(int val){
       //3 possible case
       //1st overflow
       if((front==0 && rear==size-1) || rear==front-1){
           cout<<"overflow"<<endl;
       }
       //empty
       else if(front==-1 && rear==-1){
           front++;
           rear++;
           arr[rear]=val;
       }
       //circular nature
       else if(rear==size-1 && front!=0){
           rear=0;
           arr[rear]=val;
       }else{
           rear++;
           arr[rear]=val;
       }
   }
   
   void pop(){
       //4 possible case
       //case1 Queue is empty
       if(front==-1 && rear==-1){
           cout<<"underflow"<<endl;
           return;
       }
       //case2 only 1 element is present
       else if(front==rear){
           arr[front]=-1;
           front=-1;
           rear=-1;
       }
       //circular case;
       else if(front==size-1){
           arr[front]=-1;
           front=0;
       }
       
       else{
       //case3 normal case
          arr[front]=-1;
          front++;
       }
   }
   
   bool checkEmpty(){
       if(front==-1 && rear==-1){
           return true;
       }else{
           return false;
       }
   }
   
   int getSize(){
       //3 possible case
       //empty case
       if(front==-1 && rear==-1)return 0;
       //rear>=front
       else if(rear>=front){
           return rear-front+1;
       }
       //front<rear
       else{
           return size-front+rear+1;
       }
   }
   
   int getFrontEle(){
       if(front==-1){
           cout<<"there is not front element"<<endl;
           return -1;
       }else{
           return arr[front];
       }
   }
   
   int getRearEle(){
       if(front==-1){
           cout<<"there is not front element"<<endl;
           return -1;
       }else{
           return arr[rear];
       }
   }
   void print(){
      for(int i=0;i<size;i++){
          cout<<arr[i]<<" "; 
      }
      cout<<endl;
   }
   
};

int main(){
    circularQueue cq(5);
    cq.push(5);
    cq.push(10);
    cq.push(15);
    cq.push(20);
    cq.push(25);
    
    cout<<cq.getSize()<<endl;
    cq.print();
    
    cq.pop();
    cq.pop();
    cq.print();
    
    cq.push(30);
    cq.print();
}