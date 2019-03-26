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
const int fx[] = {+0,+0,-1};
const int fy[] = {+1,-1,+0};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

char s[100][100];
int visited[100][100];
int t,row,col;
vector<string>v;

bool isValid(int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==0 && (s[x][y]=='I' || s[x][y]=='E' || s[x][y]=='H' || s[x][y]=='O' || s[x][y]=='V' || s[x][y]=='A' || s[x][y]=='#'))
        return true;
    else
        return false;
}

void dfs(int a1,int b1,int a2,int b2)
{
    visited[a1][b1]=1;

    if(s[a1][b1]==s[a2][b2])
    {
        return;
    }

    for(int i=0; i<3; i++)
    {
        int xx=a1+fx[i];
        int yy=b1+fy[i];
        if(isValid(xx,yy))
        {
            if(i==2)
                v.pb("forth");
            else if(i==0)
                v.pb("right");
            else if(i==1)
                v.pb("left");
            dfs(xx,yy,a2,b2);
        }
    }
}

int main()
{
    int a1,b1,a2,b2;
    string str;
    scin(t);
    while(t--)
    {
        scin2(row,col);
        zero(visited);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='@')
                {
                    a1=i;
                    b1=j;
                }
                if(s[i][j]=='#')
                {
                    a2=i;
                    b2=j;
                }
            }
        }
        dfs(a1,b1,a2,b2);
        for(int i=0; i<v.size(); i++)
        {
            if(i==v.size()-1)
                cout<<v[i];
            else
                cout<<v[i]<<" ";
        }
        cout<<endl;
        v.clear();
    }

    return 0;
}

