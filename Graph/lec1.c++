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
        //print the graph
        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<"{";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<"}";
            }
        }

        //BFS TRAVERSAL
        void bfsTraversal(int node){
            queue<int>q;
            unordered_map<int,bool>visited;
            q.push(node);
            visited[node]=true;

            while(!q.empty()){
                int frontNode=q.front();
                q.pop();
                cout<<frontNode<<",";
                for(auto nbr:adjList(frontNode)){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
        }
};