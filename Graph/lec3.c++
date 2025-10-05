//TOPOLOGICAL SORT USING BFS
//IT IS ALSO CALLED KHANS ALGORITHM
class Solution {
  public:
    void solve(vector<vector<int>>& edges,int totalNodes,vector<int>&ans,unordered_map<int,vector<int>>&adj) {
        queue<int>q;
        unordered_map<int,int>indegree;
        for(int i=0;i<totalNodes;i++){
            indegree[i]=0;
        }
        //update indegree
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            indegree[v]++;
        }
        for(int i=0;i<totalNodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto nbr:adj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //create adjlist
        unordered_map<int,vector<int>>adj;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            // u-->v
            adj[u].push_back(v);
        }
        //final ans
        vector<int>ans;
        solve(edges,V,ans,adj);
        return ans;
    }
};

//Directed Graph Cycle

/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
*//
//TOPOLOGOCAL SORT USING DFS
class Solution {
  public:
    void solveDFS(int src,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adj,vector<int>&ans){
        //inilise 
        visited[src]=true;
        //now call dfs of it neighbour of src node
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                solveDFS(nbr,visited,adj,ans);
            }
        }
        //now while backtracking push ans to src
        ans.push_back(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //create adj list
        unordered_map<int,vector<int>>adj;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            //u->v
            adj[u].push_back(v);
        }
        //create a ans varibale for final ans
        vector<int>ans;
        unordered_map<int,bool>visited;
        //for disconnected component
        for(int src=0;src<V;src++){
            if(!visited[src]){
                solveDFS(src,visited,adj,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//CYCLE DETECTION IN DIRECTED GRAPH
//WE CAN DETECT CYCLE IN GRAPH USING TOPOLOGICAL SORT
class Solution {
  public:
   void checkTopoLogicalsort(unordered_map<int,vector<int>>&adj,int v,vector<vector<int>> &edges,vector<int>&topo){
        unordered_map<int,int>indegree;
        queue<int>q;
        for(int i=0;i<v;i++){
            indegree[i]=0;//inilise with 0
        }
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            //u->v
            indegree[v]++;
        }
        //check which ever ele have indgree 0 push them in queue
        for(auto i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //bfs main logic
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            topo.push_back(frontNode);
            for(auto nbr:adj[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //crete adjlist
        unordered_map<int,vector<int>>adj;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            //u->v
            adj[u].push_back(v);
        }
        vector<int>topo;//topo order
        //check topological sort using bfs 
        //at the end compore their lengh
        //if lenght is same then cycle is not present
        //else present
        checkTopoLogicalsort(adj,V,edges,topo);
        if(topo.size()==V){
            return false;
        }else{
            return true;
        }
    }
};