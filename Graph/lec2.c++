////-------QUESTION---------------
/*Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 633K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. The graph can have multiple component.
*/

//----------USING BFS-------------------
class Solution {
public:
    bool checkCycleBFS(int src, vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> parent(adj.size(), -1);
        queue<int> q;

        visited[src] = true;
        q.push(src);

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            for(auto nbr : adj[currNode]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = currNode;
                    q.push(nbr);
                } else if(nbr != parent[currNode]){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        for(int src = 0; src < V; src++){
            if(!visited[src]){
                if(checkCycleBFS(src, adj)) return true;
            }
        }
        return false;
    }
};

//----------USING DFS----------------------

class Solution {
public:
    bool dfsHelper(int src, unordered_map<int, vector<int>>& adj, int parent, unordered_map<int, bool>& visited) {
        visited[src] = true;
        
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                if (dfsHelper(nbr, adj, src, visited)) 
                    return true;
            } 
            else if (nbr != parent) {
                return true;
            }
        }
        return false;  // if no cycle found from this path
    }

    bool checkCycleDFS(unordered_map<int, vector<int>>& adj, int V) {
        unordered_map<int, bool> visited;
        
        // handle disconnected components
        for (int src = 0; src < V; src++) {
            if (!visited[src]) {
                if (dfsHelper(src, adj, -1, visited)) 
                    return true;
            }
        }
        return false; // no cycle in any component
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // create adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return checkCycleDFS(adj, V);
    }
};



////--------------------------------------------

/**Directed Graph Cycle

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v. */

class Solution {
  public:
    bool dfsHelper(int src, unordered_map<int, vector<int>>& adj,
                   unordered_map<int, bool>& visited,
                   unordered_map<int, bool>& dfsTracker) {
        visited[src] = true;
        dfsTracker[src] = true;
        
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                bool ans = dfsHelper(nbr, adj, visited, dfsTracker); // FIXED here
                if (ans) {
                    return true;
                }
            } else if (dfsTracker[nbr]) { // already in current recursion stack
                return true;
            }
        }
        
        // backtrack: remove from recursion stack
        dfsTracker[src] = false;
        return false;
    }

    bool checkCycleDFS(int V, unordered_map<int, vector<int>>& adj) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;
        
        for (int src = 0; src < V; src++) {
            if (!visited[src]) {
                bool ans = dfsHelper(src, adj, visited, dfsTracker);
                if (ans) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v); // directed graph
        }
        return checkCycleDFS(V, adj);
    }
};
