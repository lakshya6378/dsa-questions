#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
void dfs(int v, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;
    for (int neighbour : adj[v])
    {
        if (!visited[neighbour])
            dfs(neighbour, adj, visited, st);
    }
    st.push(v);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
    vector<int>topological;
    topological=topoSort(n,adj);
    for(int i=0;i<n;i++)
    cout<<topological[i]<<" ";
}