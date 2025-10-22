//DETECT CYCLE USING BFS
// vector<int>findSortesPath(int src,int target){
//         queue<int>q;
//         unordered_map<int,bool>visited;
//         unordered_map<int,int>parent;
        
//         q.push(src);
//         visited[src]=true;
//         parent[src]=-1;
        
//         while(!q.empty()){
//             int frontNode=q.front();
//             q.pop();
//             for(auto nbr:adj[frontNode]){
//                 if(!visited[nbr]){
//                     visited[nbr]=true;
//                     q.push(nbr);
//                     parent[nbr]=frontNode;
//                 }
//             }
//         }
//         //shortest Path
//         vector<int>path;
//         int node=target;
        
//         while(node!=-1){
//             path.push_back(node);
//             node=parent[node];
//         }
//         //reverse it for actual ans
//         reverse(path.begin(),path.end());
//         return path;
//     }


#include<bits/stdc++.h>
using namespace std;
//FIND SHORTEST PATH USING BFS
vector<int>shortestPathBFS(vector<vector<int>>edges,int src,int target){
    //creating adlist
    unordered_map<int,vector<int>>adjList;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];

        adjList[u].push_back(v);
    }
    
    queue<int>q;
    unordered_map<int,int>parent;
    unordered_map<int,bool>visited;

    q.push(src);
    visited[src]=true;
    parent[src]=-1;

    
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        for(auto nbr:adjList[frontNode]){
            if(!visited[nbr]){
                visited[nbr]=true;
                parent[nbr]=frontNode;
            }
        }

    }

    vector<int>path;//ans
    int node=target;

    while(node!=-1){//i.e not reach to src
        path.push_back(node);
        node=parent[node];//update node to its parent node
    }
    //at last just reverse it 
    reverse(path.begin(),path.end());
    return path;
}