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
const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


string s="abcdefgh";
map<char,int>Mp;
char arr[10];
int i,j;
int level[10][10];
int visited[10][10];

void mapping()
{
    int cnt=0;
    rep(i,0,8)
    {
        Mp[s[i]]=++cnt;
        int a=Mp[s[i]];
        arr[a]=s[i];
    }
}

bool isValid(int x,int y)
{
    if(x>=1 && x<9 && y>=1 && y<9 && visited[x][y]==0)
        return true;
    else
        return false;
}

void bfs(int x1,int y1,int x2,int y2)
{
    rep(i,1,9)
    {
        rep(j,1,9)
        {
            visited[i][j]=0;
            level[i][j]=0;
        }
    }
    queue<pii>q;
    q.push(mp(x1,y1));
    visited[x1][y1]=1;
    level[x1][y1]=0;

    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        rep(i,0,8)
        {
            int xx=a+fx[i];
            int yy=b+fy[i];

            if(isValid(xx,yy))
            {
                level[xx][yy]=level[a][b]+1;
                q.push(mp(xx,yy));
                visited[xx][yy]=1;
            }
        }
    }
    pf("To get from %c%d to %c%d takes %d knight moves.\n",arr[x1],y1,arr[x2],y2,level[x2][y2]);
}

int main()
{
    mapping();
    string a,b;
    while(cin>>a>>b)
    {
        int x1=Mp[a[0]];
        int y1=a[1]-'0';

        int x2=Mp[b[0]];
        int y2=b[1]-'0';

        bfs(x1,y1,x2,y2);
    }
    return 0;
}


