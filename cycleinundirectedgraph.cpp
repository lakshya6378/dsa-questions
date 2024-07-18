#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    queue<int> q;
    unordered_map<int, int> parent;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            parent[i] = -1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int i = 0; i < adj[node].size(); i++)
                {
                    if (visited[adj[node][i]] && adj[node][i] != parent[node])
                    {
                        return true;
                    }
                    if (!visited[adj[node][i]])
                    {
                        q.push(adj[node][i]);
                        parent[adj[node][i]] = node;
                        visited[adj[node][i]] = true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "enter the number of Nodes";
    cin >> n;
    int m;
    cout << "enter the number of edges";
    cin >> m;
    cout<<"enter all the edges of the graph";
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    cout<<"hello"<<isCycle(n,adj);
}