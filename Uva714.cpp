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

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vl v,vec;

ll BinSearch(ll x,ll m,ll mx)
{
    ll low=mx;
    ll high=x;
    ll mid,result;

    while(low<=high)
    {
        mid=(low+high)/2;
        ll sum=0,cnt=1;
        for(int i=0; i<v.size(); i++)
        {
            sum+=v[i];
            if(sum>mid)
            {
                sum=v[i];
                cnt++;
                //i--;
            }
        }
        //cout<<cnt<<" "<<low<<" "<<high<<" "<<mid<<endl;
        if(cnt<=m)
        {
            result=mid;
            high=mid-1;
        }
        else if(cnt>m)
        {
            low=mid+1;
        }
    }
    return result;
}

void test(ll x,ll m)
{
    ll sum=0;
    for(int k=m; k>0; k--)
    {
        //cout<<k<<endl;
        for(int i=vec[vec.size()-1]; i>=k; i--)
        {
            sum+=v[i];
            //cout<<sum<<endl;
            if(sum==x)
            {
                vec.pb(i-1);
                sum=0;
                break;
            }
            else if(sum>x)
            {
                vec.pb(i);
                sum=0;
                break;
            }
            else
            {
                if(i==k)
                {
                    vec.pb(i-1);
                    sum=0;
                    break;
                }
            }
        }
    }

    reverse(vec.begin(),vec.end());

    //vec.erase(unique(vec.begin(),vec.end()),vec.end());

    int cnt=0;
    for(int i=0; i<vec.size(); i++)
    {
        // cout<<vec[i]<<endl;
        for(int j=cnt; j<=vec[i]; j++)
        {
            if(j==vec[i] && i==vec.size()-1)
            {
                cout<<v[j];
            }
            else
            {
                cout<<v[j]<<" ";
            }

            cnt++;
        }
        if(i!=vec.size()-1)
        {
            cout<<"/ ";
        }
    }
    cout<<endl;
}

int main()
{
    //output;
    ll t,n,m,a;
    scln(t);
    while(t--)
    {
        scln2(n,m);
        ll sum=0,mx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            scln(a);
            v.pb(a);
            sum+=a;
            mx=max(mx,a);
        }
        ll x=BinSearch(sum,m,mx);
        //cout<<x<<endl;
        vec.pb(n-1);
        test(x,m-1);
        vec.clear();
        v.clear();
    }
    return 0;
}

/*
3
5 3
100 200 300 400 500
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100
*/


