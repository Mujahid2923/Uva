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
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


int visited[1005][1005];
int level[1005][1005];
int arr[1005][1005];
int row,col;

bool isValid(int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==0 && arr[x][y]==2)
        return true;
    else
        return false;
}

void bfs(int x1,int y1,int x2,int y2)
{
    int i,j;
    rep(i,0,row)
    {
        rep(j,0,col)
        {
            visited[i][j]=0;
            level[i][j]=0;
        }
    }

    queue<pii>q;
    visited[x1][y1]=1;
    level[x1][y1]=0;
    q.push(mp(x1,y1));

    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        rep(i,0,4)
        {
            int xx=fx[i]+a;
            int yy=fy[i]+b;
            if(isValid(xx,yy))
            {
                q.push(mp(xx,yy));
                level[xx][yy]=level[a][b]+1;
                visited[xx][yy]=1;
            }
        }
    }
    pf("%d\n",level[x2][y2]);
}

int main()
{
    //output;
    int n,r,i,j,a,b,x1,y1,x2,y2;
    while(cin>>row>>col)
    {
        if(row==0 && col==0)
        {
            break;
        }

        rep(i,0,row)
        {
            rep(j,0,col)
            {
                arr[i][j]=2;
            }
        }

        scin(n);
        while(n--)
        {
            scin(a);
            scin(r);
            while(r--)
            {
                scin(b);
                arr[a][b]=1;
            }
        }
        scin2(x1,y1);
        scin2(x2,y2);
        bfs(x1,y1,x2,y2);
    }
    return 0;
}
