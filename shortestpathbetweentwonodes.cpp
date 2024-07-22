#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include<algorithm>
using namespace std;
vector<int> shortestPath(int N, vector<int> adj[], int src,int dest)
{
    // code here
    vector<int> ans;
    unordered_map<int,int>parent;
    queue<int> q;
    vector<bool> visited(N, false);
    q.push(src);
    visited[src] = true;
    parent[src]=-1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour]=node;
            }
        }
    }
    int currentnode=dest;
    ans.push_back(dest);
    while(currentnode!=src)
    {
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
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
    int src;
    cout << "enter the src node";
    cin >> src;
    int dest;
    cout<<"enter the destination node";
    cin>>dest;
    vector<int>ans;

    ans = shortestPath(n, adj, src,dest);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"-->"<<" ";
        
}