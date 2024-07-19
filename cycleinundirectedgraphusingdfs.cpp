#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
bool dfs(int v,int V,vector<int>adj[],vector<bool>visited,int parent)
{
   visited[v]=true;
   for(auto neighbour:adj[v])
   {
    if(!visited[neighbour])
    {
       bool ans= dfs(neighbour,V,adj,visited,v);
       if(ans==1)
       return true;
    }
    else if(neighbour!=parent)
    {
        return true;
    }
   }
   return false;

}
bool isCycle(int V,vector<int>adj[])
{
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
           bool ans=dfs(i,V,adj,visited,-1);
           if(ans==1)
           return true;
        }
    }

return false;
}
int main()
{
    int n,m;
    cout<<"enter the number of nodes";
    cin>>n;
    cout<<"enter the number of edges";
    cin>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<isCycle(n,adj);
}