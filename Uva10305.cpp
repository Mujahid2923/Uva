#include<bits/stdc++.h>
#define PII pair<int,int>
#define aint(v) v.begin(),v.end()

using namespace std;

/*bool cmp(int a, int b)
{
    return a>b;
}
*/
vector<int>adj[1000];
int visited[1000];
stack<int> st;

void dfs(int s)
{
    if(visited[s]==1)
    {
        return;
    }
    visited[s] = 1;
    for(int i = 0; i < adj[s].size(); i++)
    {
        int v=adj[s][i];
        dfs(v);
    }
    st.push(s);
}

int main()
{
    //freopen("in.txt","w",stdout);
    int node,edge,a,b;

    memset(visited,0,sizeof visited);
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    /*for(int i = 0; i < node; i++)
    {
        sort(aint(adj[i]),cmp);
    }*/
    for(int i = 1; i <= node; i++)
    {
        if(visited[i]==0)
            dfs(i);
    }

    bool fg = 0;
    while(!st.empty())
    {
        if(fg)
            cout<<' ';
        fg = 1;
        cout<<(int)st.top();
        st.pop();
    }
    cout<<endl;
    /* for(int i=0; i<=node; i++)
     {
         adj[i].clear();
     }*/
    return 0;
}
