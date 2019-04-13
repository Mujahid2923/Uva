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
#define        zero(a)             memset(a,0,sizeof a)
#define         all(v)             v.begin(),v.end()

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vl adj[100005];
map<ll,ll>Mp;
ll visited[100005];
set<ll>st;

void bfs(ll s)
{
    zero(visited);
    queue<ll>q;
    q.push(s);
    visited[s]=1;
    Mp[s]=1;

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            ll v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
                Mp[v]=Mp[u]+1;
            }
        }
    }
}

int main()
{
    //output;
    ll n,i,a,b,k=0;
    while(cin>>n)
    {
        if(n==0)
            break;
        rep(i,0,n)
        {
            scln2(a,b);
            st.insert(a);
            st.insert(b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        ll x,y;
        while(cin>>x>>y)
        {
            if(x==0 && y==0)
                break;
            k++;
            bfs(x);
            ll cnt=0;
            for(auto f : st)
            {
                if(Mp[f]>y+1)
                    cnt++;
                else if(Mp[f]==0)
                    cnt++;
            }
            pf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",k,cnt,x,y);
            Mp.clear();
        }
        for(auto f : st)
        {
            adj[f].clear();
        }
        st.clear();
    }
    return 0;
}

