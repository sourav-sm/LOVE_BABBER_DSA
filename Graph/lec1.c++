#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        //create adj list
        unordered_map<int,vector<int>>adjList;

        //if direction==1 then directed else undirected
        void addEdges(int u,int v,bool direction){
            if(direction==1){
                //directed
                adjList[u].push_back(v);
            }else{
                //undirected
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
};