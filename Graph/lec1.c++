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
        /*
output-- 2{1,4,}
        4{3,1,2,}
        3{0,4,1,}
        1{0,3,4,2,}
        0{1,3,}
        */

        //BFS TRAVERSAL
         void bfs(int src){
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            int frontNode=q.front();
            cout<<frontNode<<" ";
            q.pop();
            for(auto nbr:adj[frontNode]){
                //we have to check weather that node is visited or not
                if(!visited[nbr]){
                    q.push(nbr);//push to queue;
                    visited[nbr]=true;
                }
            }
        }
        }//0 1 3 4 2 

        //DFS TRAVERSAL
        void dfsHelper(int src,unordered_map<int,bool>&visited){
        cout<<src<<",";
        visited[src]=true;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
            dfsHelper(nbr,visited);
        }   
        }
      }
    
        void dfs(int src){
            unordered_map<int,bool>visited;
            dfsHelper(src,visited);//recursive call
        }
};

int main()
{
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,3,0);
    g.addEdge(3,4,0);
    g.addEdge(1,3,0);
    g.addEdge(4,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,4,0);
    
    g.printGraph();

    g.bfs(0);
    
    return 0;
}