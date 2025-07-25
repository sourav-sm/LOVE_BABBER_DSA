#include<bits/stc++.h>
using namespace std;

// 496. Row with Maximum 1’s
//You are given a non-empty grid mat with n rows and m columns consisting of only 0s and 1s. Each row in the grid is sorted in ascending order. 
//Your task is to find the index of the row with the maximum number of 1s. If multiple rows have the same number of 1s, return the index of the first such row. If no row contains at least one 1, return -1.

int rowWithMaxOnes(const vector<vector<int>>& mat) {
    int maxOnes=0;
    int maxIdx=-1;//as we have to return the index
    for(int i=0;i<mat.size();i++){
        auto it=lower_bound(mat[i].begin(),mat[i].end(),1);
        int firstIdx=it-mat[i].begin();//to convert into int from itetor
        int ones=mat[i].size()-firstIdx;

        if(ones>maxOnes){
            maxOnes=ones;
            maxIdx=i;//update the index
        }
    }
    return maxIdx;
    return -1;
}

// 1901. Find a Peak Element II
/** A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
***/
class Solution {
public:
    int find(vector<vector<int>>mat,int n,int j){
        int maxEle=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][j]>maxEle){
                maxEle=mat[i][j];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int maxRowIdx=find(mat,n,mid);//row index
            int left=mid-1>=0?mat[maxRowIdx][mid-1]:INT_MIN;
            int right=mid+1<m?mat[maxRowIdx][mid+1]:INT_MIN;

            if(mat[maxRowIdx][mid]>left && mat[maxRowIdx][mid]>right){
                return {maxRowIdx,mid};
            }else if(mat[maxRowIdx][mid]<left){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return {};
    }
};

class Solution {
public:
    bool canKokoFinsihBananaswithKSpeed(vector<int>piles,int h,int k){
        long long totalHrsTakenbyKokotoFinishallBananswithgivenk=0;
        for(int i=0;i<piles.size();i++){
            totalHrsTakenbyKokotoFinishallBananswithgivenk+=ceil(piles[i]/(double)k);
        }
        return totalHrsTakenbyKokotoFinishallBananswithgivenk<=h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            int k=mid;
            if(canKokoFinsihBananaswithKSpeed(piles,h,k)){
                //koko will finish all banans;
                ans=k;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};