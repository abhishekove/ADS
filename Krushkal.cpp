#include<iostream>
#include<string>
#define INF 9999
using namespace std;

class prim
{
    bool visited[10];
    int G[10][10],min,cost,s,e,nE,nV;

public:
        prim()
        {
            for(int i=0;i<10;i++)
                visited[i]=false;

            for(int i=0;i<10;i++)
                for(int j=0;j<10;j++)
                    G[i][j]=INF;

            min=INF;
            cost=s=e=0;
        }

        void Read_graph();
        void Min_Cost();
};


void prim :: Read_graph()
{
    cout<<"Enter No Of Vertices & Edges Respectively: ";
    cin>>nV>>nE;

    for(int i=0;i<nE;i++)
    {
        cout<<"Enter Start End Vertex And Cost Respectively: ";
        cin>>s>>e>>cost;

        G[s][e]=cost;
        G[e][s]=cost;
    }

}


void prim :: Min_Cost()
{
    int Min_cost=0;


    for(int i=0;i<nE;i++)
    {
        while(!visited[i])
        {

            min=INF;

            for(int i=0;i<nV;i++)
            {
                for(int j=0;j<nV;j++)
                {
                    if(!visited[i] && G[i][j]<min)
                        min=G[i][j];
                }
            }

            cout<<"Min: "<<min<<endl;
             Min_cost=Min_cost+min;

            for(int i=0;i<nV;i++)
            {
                for(int j=0;j<nV;j++)
                {
                    if(G[i][j]==min)
                    {
                        visited[i]=visited[j]=true;
                        G[i][j]=INF;
                        break;
                    }

                }
            }
        }

    }

    cout<<"Min Cost: "<<Min_cost<<endl;
}


int main()
{
    prim p;
    p.Read_graph();
    p.Min_Cost();

    return 0;
}



