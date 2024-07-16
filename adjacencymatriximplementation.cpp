#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>createadjacencymatrix(vector<vector<int>>arr,int n)
{
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<arr.size();i++)
    {
        int x=arr[i][0];
        int y=arr[i][1];
        ans[x-1][y-1]=1;
        ans[y-1][x-1]=1;
    }
    return ans;
}
int main()
{
    int n,m;
    cout<<"enter number of vertices and edges";
    cin>>n>>m;
    vector<vector<int>>ans;
    vector<vector<int>>arr(m,vector<int>(2,0));
    cout<<"enter the edges of the graph"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    ans =createadjacencymatrix(arr,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }

}