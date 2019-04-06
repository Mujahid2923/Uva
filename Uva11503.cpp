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

map<string,int>Mp;
map<int,int>Mp3;
vector<pii>vec;
int parent[100005];
int group[100005];

int Find(int r)
{
    if(parent[r]==r)
        return r;
    else
        return parent[r]=Find(parent[r]);
}

void Union(int a,int b)
{
    int u=Find(a);
    int v=Find(b);
    if(u!=v)
    {
        parent[v]=u;
        group[u]+=group[v];
    }
    pf("%d\n",group[u]);
}

int main()
{
    //input;
    //output;
    int t,n;
    string a,b;
    scin(t);
    while(t--)
    {
        int n,cnt=0;
        scin(n);
        while(n--)
        {
            cin>>a>>b;
            if(Mp.find(a)==Mp.end())
            {
                Mp[a]=++cnt;
                parent[cnt]=cnt;
                group[cnt]=1;
            }
            if(Mp.find(b)==Mp.end())
            {
                Mp[b]=++cnt;
                parent[cnt]=cnt;
                group[cnt]=1;
            }
            Union(Mp[a],Mp[b]);
        }
        Mp.clear();
    }
    return 0;
}

/*
1
4
a b
c e
d b
e f

output:2 2 3 3

1
4
a b
c e
d b
e d
output:2 2 3 5

*/



