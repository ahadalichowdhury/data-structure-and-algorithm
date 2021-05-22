#include<bits/stdc++.h>
#define White 1
#define Gr 2
#define Bl 3
#define nil -1
#define inf 100
using namespace std;
int vertex,edge,Time;
int G[100][100],pre[100],color[100],d[100],f[100];


void creategraph();
void dfs();
void dfs_visit(int u);
void print_df();

int main()
{
	creategraph();
	dfs();
	printf("\nResult of dfs traversal : \n");
	printf("vertex\td/f\n");
	print_df();


}

void creategraph()
{
	cout << "Vertex : ";
    cin >> vertex;
    int maxedge = vertex*(vertex-1);
    int sourse,destin;
    for(int i=1; i<=maxedge; i++)
    {
        cout << "ENTER EDGE "<<i<<": ";
        cin >> sourse >> destin;
        if(sourse==-1 && destin==-1)
        {
            break;
        }
        if(destin>=vertex||sourse<0 || destin<0 )
        {
            cout << "Invalid index\n";
            i--;
        }
        else
        {
            G[sourse][destin]=1;
        }
    }
}

void dfs()
{

	int u;
	for(u=0; u<vertex; u++)
	{
        color[u]=White;
        pre[u]=nil;
        d[u]= inf;
        f[u]=inf;
	}
    Time=0;

    for(u=0; u<vertex; u++)
    {
        if(color[u]==White)
        {
            dfs_visit(u);
        }
    }


}

void dfs_visit(int u)
{
    color[u]=Gr;
    Time++;
    d[u]=Time;

    int v;
    for(v=0; v<vertex; v++)
    {
        if(G[u][v]==1 && color[v]==White)
        {
            pre[v]= u;
            dfs_visit(v);

        }

    }
    Time++;
    f[u]=Time;
    color[u]= Bl;
}

void print_df()
{
   int i;
   for(i=0; i<vertex; i++)
   {

      printf("%d\t%d/%d\n", i, d[i], f[i]);

   }


}
