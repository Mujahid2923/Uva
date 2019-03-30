#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

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

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<string>vec;
vector<int>adj[100005];
map<char,int>Mp;
char arr[100005];
set<char>st;
int ar[100005];
int visited[100005];
stack<int>sta;

void dfs(int u)
{
    visited[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
            dfs(v);
    }
    sta.push(u);
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="#")
        {
            break;
        }
        vec.pb(s);
    }

    int cnt=0;
    for(int i=0; i<vec.size(); i++)
    {
        string str=vec[i];
        for(int j=0; j<str.size(); j++)
        {
            char ch=str[j];
            st.insert(ch);
            if(Mp.find(ch)==Mp.end())
            {
                Mp[ch]=++cnt;
            }
            int a=Mp[ch];
            arr[a]=ch;
        }
    }

    for(int i=0; i<vec.size(); i++)
    {
        string str1=vec[i];
        string str2=vec[i+1];
        int mn=min(str1.size(),str2.size());
        for(int j=0; j<mn; j++)
        {
            char c1=str1[j];
            char c2=str2[j];

            if(c1!=c2)
            {
                adj[Mp[c1]].pb(Mp[c2]);
                break;
            }
        }
    }


    for(auto i : st)
    {
        if(visited[Mp[i]]==0)
        {
            dfs(Mp[i]);
        }
    }

    while(!sta.empty())
    {
        int x=sta.top();
        cout<<arr[x];
        sta.pop();
    }
    cout<<endl;
    return 0;
}


