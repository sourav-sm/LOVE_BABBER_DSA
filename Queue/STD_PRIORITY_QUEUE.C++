#include<iostream>
#include<queue>
using namespace std;

int main(){
  //MIN-HEAP
  //SAME AS MAX-HEAP JUST THE DIFF IS HERE WE STORE MIN ELEMENTS AT TOP INSEAD OF MAX

    priority_queue<int,vector<int>,greater<int>>pq1;
    //INITIALIZATION OF PRIORITY_QUEUE AS MINHEAP

    pq1.push(5);
    //pq1-->5
    pq1.push(10);
    //pq1-->5,10
    pq1.push(15);
    //pq1-->5,10,15
    pq1.push(2);
    //pq1-->2,5,10,15
    pq1.push(3);
    //pq1-->2,3,5,10,15

    cout<<"Top element of priority queue"<<pq1.top()<<endl;
    //2

    if(pq1.empty()==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    //pq1-->2,3,5,10,15
    cout<<endl;

    if(!pq1.empty())pq1.pop();
    //pq1-->3,5,10,15
    
    cout<<"Top element of priority queue"<<pq1.top()<<endl;
    //2

    cout<<"size of priority queue"<<pq1.size()<<endl;
    //4


    //*****MAX--HEAP*********----------------------------------------------------------------
    priority_queue<int>pq;
    pq.push(5);
    //pq-->5
    pq.push(10);
    //pq-->10,5
    pq.push(15);
    //pq-->15,10,5
    pq.push(55);
    //pq-->55,15,10,5
    pq.push(20);
    //pq-->55,20,15,10,5

    cout<<"Top element of priority queue"<<pq.top()<<endl;
    //55

    if(pq.empty()==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    if(!pq.empty())pq.pop();
    //pq-->20,15,10,5
    
    cout<<"Top element of priority queue"<<pq.top()<<endl;
    //20

    cout<<"size of priority queue"<<pq.size()<<endl;
    //4

}