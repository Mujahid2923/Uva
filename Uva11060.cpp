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


vector<string>v1,st;
vector<int>vec;
map<string,int>Mp;
map<int,int>kom;
string arr[1000];
vector<int>adj[1000];
int visited[1000];
priority_queue<int,vector<int>,greater<int> >pq;
int n;

void check()
{
    int cnt=1;
    for(auto s : st)
    {
        Mp[s]=cnt++;
        int a=Mp[s];
        arr[a]=s;
    }
//    for(int i=1; i<=n; i++)
//    {
//        cout<<arr[i]<<" represents "<<Mp[arr[i]]<<endl;
//    }
}


int main()
{
    int f=0,edge;
    string s,s2,s3;
    while(cin>>n)
    {
        f++;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            st.pb(s);
        }
        check();

        cin>>edge;
        for(int i=0; i<edge; i++)
        {
            cin>>s2>>s3;
            kom[Mp[s3]]++;
            adj[Mp[s2]].pb(Mp[s3]);
            // cout<<Mp[s2]<<" "<<Mp[s3]<<endl;
        }

        for(int i=1; i<=n; i++)
        {
            sort(adj[i].begin(),adj[i].end());
        }

//        for(int i=1; i<=n; i++)
//        {
//           for(int j=0;j<adj[i].size();j++)
//           {
//               cout<<adj[i][j]<<" ";
//           }
//           cout<<endl;
//        }

        int sou;
        for(auto str : st)
        {
            if(kom[Mp[str]]==0)
            {
                sou=Mp[str];
                pq.push(sou);
                visited[sou]=1;
                //break;
            }
        }


        while(!pq.empty())
        {
            int x=pq.top();
            //cout<<x<<endl;
            vec.pb(x);
            pq.pop();

            for(int i=0; i<adj[x].size(); i++)
            {
                int v=adj[x][i];
                kom[v]--;
                //cout<<v<<endl;

                if(kom[v]==0 && visited[v]==0)
                {
                    pq.push(v);
                    visited[v]=1;
                }
            }
        }


        pf("Case #%d: Dilbert should drink beverages in this order: ",f);
        for(int i=0; i<vec.size(); i++)
        {
            int z=vec[i];
            if(i==vec.size()-1)
            {
                cout<<arr[z]<<".";
            }
            else
            {
                cout<<arr[z]<<" ";
            }
        }
        cout<<endl<<endl;

        for(int i=1; i<=n; i++)
        {
            adj[i].clear();
        }
        zero(arr);
        st.clear();
        Mp.clear();
        kom.clear();
        zero(visited);
        vec.clear();
        v1.clear();
    }
    return 0;
}


