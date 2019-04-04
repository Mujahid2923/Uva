///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define       zero(a)              memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int node,edge;
map<string,int>Mp;
string arr[1005];
vector<int>adj[1005];
vector<int>radj[1005];
int visited[1005];
int color[1005];
stack<int>st;

void dfs(int u)
{
    color[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(color[v]==0)
        {
            dfs(v);
        }
    }
    st.push(u);
}

void ssc(int u)
{
    visited[u]=1;

    for(int i=0; i<radj[u].size(); i++)
    {
        int v=radj[u][i];
        if(visited[v]==0)
        {
            ssc(v);
        }
    }
}

int main()
{
    string a,b,c,d;

    while(cin>>node>>edge)
    {
        int cnt=0;
        if(node==0 && edge==0)
        {
            break;
        }
        for(int i=0; i<node; i++)
        {
            cin>>a>>b;
            string s=a+b;
            Mp[s]=++cnt;
        }

        for(int i=0; i<edge; i++)
        {
            cin>>a>>b>>c>>d;
            string s1=a+b;
            string s2=c+d;
            adj[Mp[s1]].pb(Mp[s2]);
            radj[Mp[s2]].pb(Mp[s1]);
        }
        for(int i=1; i<=node; i++)
        {
            if(color[i]==0)
            {
                dfs(i);
            }
        }

        int rate=0;
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(visited[x]==0)
            {
                ssc(x);
                rate++;
            }
        }
        pf("%d\n",rate);
        for(int i=1; i<=node; i++)
        {
            adj[i].clear();
            radj[i].clear();

        }
        Mp.clear();
        zero(visited);
        zero(color);
    }

    return 0;
}


