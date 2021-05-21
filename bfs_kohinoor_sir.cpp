#include<bits/stdc++.h>
#define White 1
#define Gr 2
#define Bl 3
#define nil -1
#define inf 100
using namespace std;
int vertex,edge,Rear=-1,Front=0;
int G[100][100],pre[100],color[100],d[100],Queue[100];

int Dequeue()
{
    int s;
    if(Front>Rear)
    {
        cout << "NO VERTEX ! QUEUE IS EMPTY\n";
        exit(1);
    }
    s = Queue[Front];
    Front = Front+1;
    return s;
}

void Enqueue(int s)
{
    if(Rear == 100-1)
        cout<<"Over\n";
    else
    {
        Rear = Rear+1;
        Queue[Rear]=s;
    }
}
void Display()
{
    for(int i=1; i<=vertex; i++)
    {
        for(int j=1; j<=vertex; j++)
        {
            cout << G[i][j]<<" ";
        }
        cout << "\n";
    }
}
int isEmpty_queue()
{
    if(Front>Rear)
        return 1;
    else
        return 0;
}
void Print_path(int s,int v)
{
    if(s==v)
    {
        cout << s << " ";
    }
    else if(pre[v]==nil)
    {
        cout << "NO path.";
    }
    else
    {
        Print_path(s,pre[v]);
        cout << v << " ";
    }
}
void Tabel()
{

    cout << "VERTEX        : ";
    for(int i=0; i<vertex; i++)
    {
        cout << i <<"\t";
    }
    cout<<"\n";
    cout << "COLOR         : ";
    for(int i=0; i<vertex; i++)
    {
        if(color[i]==Bl)
            cout << "BLACK"<<"\t";
        else if(color[i]==Gr)
            cout << "GRAY"<<"\t";
        else if(color[i]==White)
            cout << "WHITE"<<"\t";
    }
    cout << "\n";
    cout << "DESTINATION   : ";
    for(int i=0; i<vertex; i++)
    {
        cout << d[i] << "\t";
    }
    cout << "\n";
    cout << "PREVIOUS NODE : ";
    for(int i=0; i<vertex; i++)
    {
        cout << pre[i]<<"\t";
    }
    cout << "\n";

}
void bfs()
{
    int u;
    for(u=0; u<vertex; u++)
    {
        color[u]=White;
        pre[u]=nil;
        d[u]= inf;
    }
    cout << "VERTEX        : ";
    for(int i=0; i<vertex; i++)
    {
        cout << i <<"\t";
    }
    cout<<"\n";
    cout << "COLOR         : ";
    for(int i=0; i<vertex; i++)
    {
        if(color[i]==Bl)
            cout << "BLACK"<<"\t";
        else if(color[i]==Gr)
            cout << "GRAY"<<"\t";
        else if(color[i]==White)
            cout << "WHITE"<<"\t";
    }
    cout << "\n";
    cout << "DESTINATION   : ";
    for(int i=0; i<vertex; i++)
    {
        cout << d[i] << "\t";
    }
    cout << "\n";
    cout << "PREVIOUS NODE : ";
    for(int i=0; i<vertex; i++)
    {
        cout << pre[i]<<"\t";
    }
    cout << "\n";
    int s;
    cout<<"ENTER SOURSE :";
    cin >> s;
    color[s]= Gr;
    d[s] = 0;
    pre[s] = nil;
    Enqueue(s);
    while(!isEmpty_queue())
    {
        u = Dequeue();
        for(int v =0; v<vertex; v++)
        {
            if((G[u][v]==1 )&& (color[v]==White))
            {
                color[v]=Gr;
                pre[v]=u;
                d[v]= d[u]+1;
                Enqueue(v);
            }
        }
        color[u]=Bl;
    }
    int v;
    cout << "ENTER DESTANITION OF BFS : ";
    cin >> v;

    cout << "THE path from vertex "<<s<<" to vertex "<<v<<" is : ";
    Print_path(s,v);
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

int main()
{
    creategraph();
    bfs();
    cout << "\n";
    //  Display();
    cout <<"\n";
    Tabel();
}
