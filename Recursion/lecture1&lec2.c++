#include <bits/stdc++.h>
using namespace std;
int fibonaki(int n){
    if(n==0 || n==1)return n;
    
    return fibonaki(n-1)+fibonaki(n-2);
}
// /----------------------------------------------------------------------------------------------------------

int search(vector<int>&arr,int ele,int index,int size){
   if(index>size-1){
       return -1;
   }   
   
   if(arr[index]==ele){
       return index;
   }
   
   return search(arr,ele,index+1,size);
}

// /----------------------------------------------------------------------------------------------------------

int RecursiveBinarySearch(vector<int>&arr,int ele,int s,int e){
    if(s>=e)return -1;
    int mid=(s+e)/2;
    if(arr[mid]==ele)return mid;
    else if(arr[mid]>ele){
        return RecursiveBinarySearch(arr,ele,s,mid-1);
    }else{
      return RecursiveBinarySearch(arr,ele,mid+1,e);    
    }
    
}


// /----------------------------------------------------------------------------------------------------------

bool  checkSortedRecursive(vector<int>&arr,int index,int size){
    if(index>=size-1)return true;
    if(arr[index]>arr[index+1]){
        return false;
    }
    return checkSortedRecursive(arr,index+1,size);
}

// /----------------------------------------------------------------------------------------------------------

void printAllDegit(int n){
    if(n==0)return ;
    int digit=n%10;
    // cout<<digit<<" ";//6 5 4 3 2 1
    printAllDegit(n/10);
    cout<<digit<<" ";//1 2 3 4 5 6
}



int main()
{   
    int n=15;
    cout<<fibonaki(n)<<endl;

    vector<int>arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    int ele=300;
    cout<<search(arr,ele,0,5)<<endl;

    int ele=40;
    cout<<RecursiveBinarySearch(arr,ele,0,4);

    cout<<checkSortedRecursive(arr,1,5)<<endl;

    int n=123456;
    printAllDegit(n);

    return 0;
}