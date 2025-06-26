#include<iostream>
using namespace std;

class heap{
   public:
    int arr[100];
    int size=0;
     
     heap(){
        arr[0]=-1;
        size=0;
     }
     void insert(int val){
        size=size+1;
        int idx=size;
        arr[idx]=val;

        while(idx>1){
            int parent=idx/2;

            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }else{
                return ;
            }
        }
     }

     void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};

//heapify algorithm
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

//heap sort
void heapSort(int arr[],int n){
    int size=n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}


int main(){
    heap h;
    h.insert(10);
    h.insert(50);
    h.insert(100);
    h.insert(70);
    h.insert(80);
    h.insert(1);
    h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"printing the new array "<<endl;

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"printing array after heap sort"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}