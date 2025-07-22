#include <bits/stdc++.h>
using namespace std;

/// bubble sort
void bubbleSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
//insertion sort
void insertionSort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//selection sort
void selectionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}


int main()
{
   std::vector<int>arr;
   arr.push_back(1);
   arr.push_back(5);
   arr.push_back(4);
   arr.push_back(3);
   arr.push_back(2);
   
   bubbleSort(arr);
   insertionSort(arr);
   selectionSort(arr);
   for(int i=0;i<arr.size();i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;

    return 0;
}