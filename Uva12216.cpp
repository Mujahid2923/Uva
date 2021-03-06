///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    100000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
//#define          endl                   '\n'

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

vl v, v1, v2, v3 ;
vector < pll > vec, vec1, vec2 ;
vector < ll > adj[ 200000 + 5 ] ;
map < ll, ll > Mp, Mp2, Mp3 ;
set < ll > st,st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;
multiset < ll > :: iterator it ;
pll P[ 1 + 5 ] ;

ll n, m, t ;

bool prime[ 100000 + 5 ];
void findPrime()
{
    int n = 100000 ;
    memset( prime, false, sizeof prime ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[1] = true ;

    for( int i = 3 ; i*i <= n ; i+= 2 )
    {
        if(!prime[i])
        {
            for( int j = 2 ; i*j <= n ; j++ )
            {
                prime[ i*j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        if( !prime[i] )
        {
            v.pb( i );
        }
    }
}

void factorization( ll n )
{
    for( int i = 0 ; v[i]*v[i] <= n ; i++ )
    {
        int cnt = 0 ;
        while( n % v[i] == 0 )
        {
            cnt ++ ;
            n = n / v[i] ;
        }
        if( cnt )
        {
            Mp[ v[ i ] ] = cnt * m ;
        }
    }

    if( n > 1 )
    {
        Mp[ n ] = m ;
    }
}

ll InsertAndCalculation()
{
    ll sum = 0 ;
    for( auto x : Mp )
    {
        ll a = x.second / t ;
        ll b = x.second / ( t + 1 ) ;
        ll c = a - b ;
        vec.pb( mp( 1 + a, c ) ) ;
    }

    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        ll val = vec[ i ].second ;
        for( int j = 0 ; j < vec.size() ; j ++ )
        {
            if( i == j )
                continue ;
            val = ( val * vec[ j ].first ) % MOD ;
        }
        sum = ( sum + val ) % MOD ;
        vec[ i ].first -= vec[ i ].second ;
    }
    return sum ;
}

int main()
{
    //output ;
    findPrime() ;
    int cnt = 1 ;
    while( 1 )
    {
        scln2( n , m ) ;
        scln( t ) ;
        if( n == 0 && m == 0 && t == 0 )
        {
            break ;
        }
        factorization( n ) ;

        pf( "Case %d: %lld\n", cnt, InsertAndCalculation() ) ;
        Mp.clear() ;
        vec.clear() ;
        cnt ++ ;
    }

    return 0 ;
}


///Always check for n = 1

