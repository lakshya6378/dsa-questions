#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include<queue>
using namespace std;
vector<int> shortestPath(int N,vector<int>adj[], int src)
{
    // code here
    vector<int> ans(N, 0);

    queue<pair<int, int>> q;
    vector<bool> visited(N, false);
    q.push({src, 0});
    visited[src] = true;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int node = temp.first;
        int dist = temp.second;
        ans[node] = dist;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push({neighbour, dist + 1});
                visited[neighbour] = true;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            ans[i] = -1;
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
    vector<int> ans;
    int src;
    cout<<"enter the src node";
    cin>>src;

    ans = shortestPath(n, adj,src);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}