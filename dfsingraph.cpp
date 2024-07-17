#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;
void dfs(int v, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[v] = true;
    ans.push_back(v);
    for (auto i : adj[v])
    {
        if (!visited[i])
            dfs(i, adj, visited, ans);
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        //this loop is used for the case of not connected graph.in this case edges which are not connected are remain unvisited so this loop ensure that every node is visited in graph.
        if (!visited[i])
        {
            dfs(i, adj, visited, ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr[] = {{1, 2, 3}, {}, {4}, {}, {}};
    vector<int> ans;
    ans = dfsOfGraph(5, arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
