#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
bool kahnstopologicalsort(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> degree(n, 0);
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            degree[adj[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cnt++;
        for (int neighbour : adj[temp])
        {
            degree[neighbour]--;
            if (degree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(cnt==n)
    return false;
    return true;
}
int main()
{
    int n, m;
    cout << "enter the number of nodes in the graph";
    cin >> n;
    vector<int> adj[n];
    cout << "enter the number of edges in the graph";
    cin >> m;
    cout << "enter the edges of the graph" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
   cout<<kahnstopologicalsort(n,adj);
}