#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(0);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if (visited[vertex])
            continue;
        visited[vertex] = true;
        ans.push_back(vertex);
        for (int i = 0; i < adj[vertex].size(); i++)
        {
            if (!visited[adj[vertex][i]])
                q.push(adj[vertex][i]);
        }
    }
    return ans;
}
int main()
{
    vector<int>arr[]={{1,2,3},{},{4},{},{}};
    vector<int>ans;
    ans=bfsOfGraph(5,arr);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

}
