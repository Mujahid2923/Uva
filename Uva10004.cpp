#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200];
int visited[200];

#define white 0
#define red 1
#define blue 2

int BFS(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=red;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==white)
            {
                if(visited[u]==red)
                {
                    visited[v]=blue;
                }
                else
                {
                    visited[v]=red;
                }
                q.push(v);
            }
            if(visited[u]==visited[v])
            {
                return 0;
            }

        }
    }
    return 1;

}

int main()
{
    int node,edge;
    while(cin>>node)
    {
        if(node==0)
        {
            break;
        }
        cin>>edge;
        int a,b;
        for(int i=0; i<edge; i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=BFS(0);
        if(ans==1)
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
        for(int i=0; i<200; i++)
        {
            visited[i]=white;
            adj[i].clear();
        }
    }
    return 0;

}

