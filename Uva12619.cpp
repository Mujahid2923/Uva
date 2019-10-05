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
#define          MOD                    1000000007
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

vl v, v1, v2 ;
//vector < pll > vec ;
map < ll, ll > Mp ;
set < ll > st ;
deque < ll > dq ;


bool mark[ 1000000 + 5 ];
ll pd[ 1000000 + 5 ];

void findPrime()
{
    for ( ll i = 2; i <= 1000000 ; i+= 2)
    {
        pd[ i ] = 2;
    }

    for ( ll i = 3; i <= 1000000 ; i += 2 )
    {
        if ( !mark[ i ] )
        {
            pd[ i ] = i ;
            for ( ll j = i ; ( j * i ) <= 1000000 ; j += 2 )
            {
                mark[ j * i ] = true ;
                pd[ j * i ] = i ;
            }
        }
    }
}


ll power( ll x,ll y,ll m )
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x , y/2 , m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x , y-1 , m ) % m ) ) % m ;
}

ll modInverse( ll a, ll m )
{
    return power( a , m - 2 , m ) ;
}

ll val = 0 , ans = 1 ;

ll divisor1( ll n )
{
    while( n != 1 )
    {
        ll cnt = 0 ;
        ll  x = pd[ n ] ;
        while( n % x == 0 )
        {
            n = n / x ;
            cnt ++ ;
        }

        ll y = modInverse( Mp[ x ] + 1 , MOD ) ;
        ans = ( ans % MOD * y % MOD ) % MOD ;
        Mp[ x ] += cnt ;
        ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
    }
    return ans ;
}

ll divisor2( ll n )
{
    while( n != 1 )
    {
        ll cnt = 0 ;
        ll  x = pd[ n ] ;
        while( n % x == 0 )
        {
            n = n / x ;
            cnt ++ ;
        }

        ll y = modInverse( Mp[ x ] + 1 , MOD ) ;
        ans = ( ans % MOD * y % MOD ) % MOD ;
        Mp[ x ] -= cnt ;
        ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
    }
    return ans ;
}


int main()
{
    findPrime() ;
    ll t, n, a ;
    scln( t ) ;
    for( int j = 1 ; j <= t ; j ++ )
    {
        scln( n ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scln( a ) ;
            if( a > 0 )
            {
                val = ( val % MOD + divisor1( a ) % MOD ) % MOD ;
            }
            else
            {
                val = ( val % MOD + divisor2( -a ) % MOD ) % MOD ;
            }
        }
        pf("Case %d: %lld\n", j, val ) ;
        val = 0 , ans = 1 ;
        Mp.clear() ;
    }

    return 0 ;
}


-----------------------------Another way--------------------------------------------
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
#define          MOD                    1000000007
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

vl v, v1, v2, prime ;
//vector < pll > vec ;
map < ll, ll > Mp ;
set < ll > st ;
deque < ll > dq ;


bool mark[ 1100 + 5 ];
void findPrime()
{
    ll n = 1100 ;
    memset( mark, false, sizeof mark ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        mark[ i ] = true ;
    }

    mark[ 1 ] = true ;

    for( int i = 3 ; i <= n ; i += 2 )
    {
        if( !mark[i] )
        {
            for( int j = 2 ; i*j <= n ; j++ )
            {
                mark[ i*j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        if( !mark[i] )
        {
            prime.pb( i );
        }
    }
}

ll val = 0, ans = 1 ;

ll power( ll x,ll y,ll m )
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x, y/2, m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x, y-1, m ) % m ) ) % m ;
}

ll modInverse( ll a, ll m )
{
    return power( a, m - 2, m ) ;
}


ll divisor1( ll n )
{
    for( int i = 0 ; prime[ i ] * prime[ i ] <= n ; i++ )
    {
        ll cnt = 0 ;
        while( ( n % prime[ i ] ) == 0 )
        {
            n = n / prime[ i ] ;
            cnt ++ ;
        }
        if( cnt > 0 )
        {
            ll x = prime[ i ] ;
            ll y = modInverse( Mp[ x ] + 1, MOD ) ;
            ans = ( ans % MOD * y % MOD ) % MOD ;
            Mp[ x ] += cnt ;
            ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
        }
    }

    if( n > 1 )
    {
        ll y = modInverse( Mp[ n ] + 1, MOD ) ;
        ans = ( ans % MOD * y % MOD ) % MOD ;
        Mp[ n ] ++ ;
        ans = ( ans % MOD * ( Mp[ n ] + 1 ) % MOD ) % MOD ;
    }

    return ans ;
}

ll divisor2( ll n )
{
    for( int i = 0 ; prime[ i ] * prime[ i ] <= n ; i++ )
    {
        ll cnt = 0 ;
        while( ( n % prime[ i ] ) == 0 )
        {
            n = n / prime[ i ] ;
            cnt ++ ;
        }
        if( cnt > 0 )
        {
            ll x = prime[ i ] ;
            ll y = modInverse( Mp[ x ] + 1, MOD ) ;
            ans = ( ans % MOD * y % MOD ) % MOD ;
            Mp[ x ] -= cnt ;
            ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
        }
    }

    if( n > 1 )
    {
        ll y = modInverse( Mp[ n ] + 1, MOD ) ;
        ans = ( ans % MOD * y % MOD ) % MOD ;
        Mp[ n ] -- ;
        ans = ( ans % MOD * ( Mp[ n ] + 1 ) % MOD ) % MOD ;
    }
    return ans ;
}


int main()
{
    //output ;
    findPrime() ;
    ll t, n, a ;
    scln( t ) ;
    for( int j = 1 ; j <= t ; j ++ )
    {
        scln( n ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scln( a ) ;
            if( a > 0 )
            {
                val = ( val % MOD + divisor1( a ) % MOD ) % MOD ;
            }
            else
            {
                val = ( val % MOD + divisor2( -a ) % MOD ) % MOD ;
            }
        }
        pf("Case %d: %lld\n", j, val ) ;
        val = 0, ans = 1 ;
        Mp.clear() ;
    }

    return 0 ;
}





