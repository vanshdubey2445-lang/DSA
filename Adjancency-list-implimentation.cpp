#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;
    // vector<int>adjlist[vertex];
     vector<pair<int,int>>adjlist[vertex];
    int u,v,weight;

    //undirected unweighted graph
    // for(int i=0;i<edges;i++)
    // {
    //     cin>>u>>v;
    //     adjlist[u].push_back(v);
    //     adjlist[v].push_back(u);

    // }

    //undirected weighted graph
    // for(int i=0;i<edges;i++)
    // {
    //     cin>>u>>v>>weight;
    //     adjlist[u].push_back(make_pair(v,weight));
    //     adjlist[v].push_back(make_pair(u,weight));

    // }

    //directed unweighted graph
    // for(int i=0;i<edges;i++)
    // {
    //     // cin>>u>>v>>weight;
    //     cin>>u>>v;
    //     adjlist[u].push_back(v);
    // }

    //directed weighted graph
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v>>weight;
        adjlist[u].push_back(make_pair(v,weight));
    }

    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<adjlist[i].size();j++)
        // cout<<adjlist[i][j]<<" ";
         cout<<adjlist[i][j].first<<" "<<adjlist[i][j].second<<" "; 

        cout<<endl;
    }
}