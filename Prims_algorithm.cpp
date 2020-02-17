//============================================================================
// Name        : Prims_algorithm.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stack>
#include<queue>
#define INF 100000000000
using namespace std;

class G_matrix
{
    int G[10][10], v, visited[10],e;
public:
		G_matrix();
		void read_Graph();
		void Prim_Algo();
};


G_matrix :: G_matrix()
{
    v=e=0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            G[i][j]=0;
    }
}


void G_matrix :: read_Graph()
{
    int m,n,cost;
    cout<<"Enter Number Of Vertex:";
    cin>>v;

    for(int i=0;i<v;i++)
    	for(int j=0;j<v;j++)
    		G[i][j]=INF;

    cout<<"Enter Number Of Edges:";
    cin>>e;

    for(int i=0; i<e;i++)
    {
    	cout<<"Enter Starting Vertex:";
    	cin>>m;
    	cout<<"Enter Ending Vertex:";
    	cin>>n;
    	cout<<"Enter It's Cost:";
    	cin>>cost;
    	G[m][n]=cost;
    	G[n][m]=cost;
    }
}


void G_matrix :: Prim_Algo()
{
	int dist[10],from[10],min_cost=0,min,vertex;
	cout<<"\n\nMinimum Spanning Tree Using Prim's Algorithm"<<endl;

	for(int i=0;i<v;i++)
	{
		dist[i]=G[0][i];
		from[i]=0;
		visited[i]=0;
	}

	for(int i=0;i<v-1;i++)
	{
		min=INF;
		for(int j=1;j<v;j++)
		{
			if(min>dist[j])
			{
				min=dist[j];
				vertex=j;
			}
		}

		visited[vertex]=1;
		cout<<"\nEdge: "<<from[vertex]<<"-"<<vertex<<endl;
		min_cost +=dist[vertex];
		dist[vertex]=INF;

		for(int j=0;j<=v;j++)
		{
			if(!visited[j] && G[vertex][j]<dist[j])
			{
				dist[j]=G[vertex][j];
				from[j]=vertex;
			}
		}
	}

	cout<<"Cost of Minimum Spanning Tree Using Prim's Algorithm: "<<min_cost<<endl;
}


int main()
{
	G_matrix g;
	cout<<"\n\n\n=========================== Minimum Spanning Tree ==========================="<<endl<<endl;
	g.read_Graph();
	g.Prim_Algo();

return 0;
}
