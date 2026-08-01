#include<iostream>
#include<vector>
using namespace std;

//adjancency matrix

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;
    vector<vector<bool> >adjmat(vertex,vector<bool>(vertex,0));
    int u,v,weight;
    
    //undirected unweighted graph
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        adjmat[u][v]=1;
        adjmat[v][u]=1;
    }

    //undirected weighted graph
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v>>weight;
        adjmat[u][v]=weight;
        adjmat[v][u]=weight;
    }

    //directed unweighted graph
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        adjmat[u][v]=1;
    }

    //directed weighted graph
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v>>weight;
        adjmat[u][v]=weight;
    }
    

    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        cout<<adjmat[i][j]<<" ";

        cout<<endl;
        
    }
}