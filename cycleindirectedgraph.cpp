#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
bool dfs(int v, vector<bool> visited, vector<bool> dfsvisited, vector<int> adj[])
{
    visited[v] = true;
    dfsvisited[v] = true;
    for (int neighbour : adj[v])
    {
        if (!visited[neighbour])
        {

            bool ans = dfs(neighbour, visited, dfsvisited, adj);
            if (ans)
                return true;
        }
        else if (dfsvisited[neighbour])
            return true;
    }
    dfsvisited[v] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false), dfsvisited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(i, visited, dfsvisited, adj);
            if (ans)
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cout << "enter the number of nodes";
    cin >> n;
    cout << "enter the number of edges";
    cin >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isCyclic(n, adj);
}