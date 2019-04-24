/*			Problem Statement : Represvnt a given graph using adjacency matrix and traversv each node using Depth first svarch

*/


#include<iostream>
using namespace std;

void dfs_rec(int v,int visit[],int u);
int adj[20][20];

int main()
{
    int v,e,a,b;
    cout<<"Enter the number of vertices :";
    cin>>v;
//  int adj[v][v];
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
        {
                adj[i][j] = 0;
        }

        cout<<"Enter the number of edges : ";
        cin>>e;
        for(int i=0;i<e;i++)
        {
            cout<<"Enter the edge (Starting and ending point) : ";
            cin>>a>>b;
            adj[a][b]= adj[b][a] = 1;
        }

        int visited[v];
        for(int i=0;i<v;i++)
        visited[i] =0;
        cout<<"\t\tThe Depth First Search of your graph is : ";
        dfs_rec(0,visited,v);
        cout<<"\n\n";


}
void dfs_rec(int v,int visit[],int u)
{
    cout<<v;
    visit[v] = 1;
    for(int j=0;j<u;j++)
    {
        if(adj[v][j]==1&&visit[j]==0)
            {
                dfs_rec(j,visit,u);
            }
    }
}

/*
//IF YOU WANT TO PRINT THE ADJANCENCY MATRIX OF GRAPH

cout<<"\n";

for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
                cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
*/