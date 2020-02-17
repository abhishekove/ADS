#include<iostream>
#define INF 9999
using namespace std;
class matrix
{
    int G[10][10], nV,nE;
public:
    matrix()
    {
        nV=0;
        nE=0;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                G[i][j]=0;
            }
        }

    }
    void read_Graph();
    void primfun();

};
void matrix::read_Graph()
{
	int m,n,cost;
	cout<<"\n Enter number of vertices: ";
	cin>>nV;
	for(int i=0;i<nV;++i)
	{
		for(int j=0;j<nV;++j)
		{
			G[i][j]=INF;
		}
	}
	cout<<"\n Enter number of edges: ";
	cin>>nE;
	for(int i=0;i<nE;++i)
	{
		cout<<"\n Enter start and end vertex and its cost: ";
		cin>>m>>n>>cost;
		G[m][n]=cost;
		G[n][m]=cost;
	}
}
void matrix::primfun()
{
	int dist[10],from[10],visited[10],vertex;
	cout<<"\n Minimum Spanning tree is: ";
	int minCost=0,min;
	for(int i=0;i<nV;i++)
	{
		dist[i]=G[0][i];
		from[i]=0;
		visited[i]=0;
	}
	for(int i=0;i<nV-1;i++)
	{
		min=INF;
		for(int j=1;j<nV;++j)
		{
			if(min>dist[j])
			{
				min=dist[j];
				vertex=j;

			}
		}
		visited[vertex]=1;
		cout<<"\n Edge: "<<from[vertex]<<"-"<<vertex<<"\n ";
		minCost=minCost+dist[vertex];
		dist[vertex]=INF;
		for(int j=1;j<=nV;++j)
		{
			if(!visited[j]&& G[vertex][j]<dist[j])
			{
				dist[j]=G[vertex][j];
				from[j]=vertex;
			}
		}
	}
	cout<<"\n Cost of MST: "<<minCost<<endl;
}
int main()
{
     matrix obj;
     obj.read_Graph();
     obj.primfun();
}

