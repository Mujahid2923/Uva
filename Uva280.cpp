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

vi adj[1000];
int visited[1000];
vi vec,bit,far;

void dfs(int s)
{
    for(int i=0; i<adj[s].size(); i++)
    {
        int v=adj[s][i];
        if(visited[v]==0)
        {
            visited[v]=1;
            dfs(v);
        }
    }
}

int main()
{
    //CIN;
    // output;
    int t,n,k,m,val,a,b,ck;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }

        while(cin>>k)
        {
            if(k==0)
            {
                break;
            }
            else
            {
                ck=k;
            }
            while(cin>>m)
            {
                if(m==0)
                {
                    break;
                }
                else
                {
                    adj[ck].pb(m);
                }
            }
        }

        cin>>val;
        for(int i=0; i<val; i++)
        {
            cin>>a;
            far.pb(a);
        }


        for(int i=0; i<val; i++)
        {
            dfs(far[i]);
            for(int j=1; j<=n; j++)
            {
                if(visited[j]==0)
                {
                    bit.pb(j);
                }
            }

            if(bit.empty())
            {
                cout<<0;
            }
            else
            {
                cout<<bit.size()<<" ";
            }

            for(int j=0; j<bit.size(); j++)
            {
                if(j==bit.size()-1)
                {
                    cout<<bit[j];
                }
                else
                {
                    cout<<bit[j]<<" ";
                }
            }
            cout<<endl;
            bit.clear();
            zero(visited);
        }

        for(int i=1; i<=n; i++)
        {
            adj[i].clear();
        }
        far.clear();

    }

    return 0;
}

