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
#define          db                     double
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
#define          Upper(c,x)           (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

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

vl v, vec, v1 ;
void findPrime( int n )
{
    bool prime[n];
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
            v.pb( i ) ;
        }
    }
}

map < ll, ll > Mp ;
ll val = 6 ;

void PrimeFactorization( ll n )
{
    ll f = n ;
    int ok = 0 ;
    for( int i = 0 ; v[ i ] * v[ i ] <= n ; i ++ )
    {
        ll cnt = 0 ;
        while( n % v[i] == 0 )
        {
            cnt ++ ;
            n = n / v[i] ;
        }

        if( cnt > Mp[ v[ i ] ] )
        {
            Mp[ v[ i ] ] = cnt ;
            //cout << "in ->" << v[ i ] << " " << Mp[ v[ i ] ] << endl ;
            if( v[ i ] == 5 )
            {
                val /= 2 ;
            }
            else
            {
                val *= v[ i ] ;
            }
            ok = 1 ;
            break ;
        }
    }

    if( n > 1 && ok == 0 && Mp[ n ] == 0 )
    {
        //cout << "out ->" << n << " " << Mp[ n ] << endl ;
        Mp[ n ] = 1 ;
        val *= n ;
    }

    val = val % 100 ;

    //cout << val << endl ;
    vec.pb( val % 10 ) ;
}


void Extra()
{
    vec.pb( 1 ) ;
    vec.pb( 2 ) ;
    vec.pb( 6 ) ;
    vec.pb( 2 ) ;
    vec.pb( 6 ) ;
    Mp[ 2 ] = 2 ;
    Mp[ 3 ] = 1 ;
    Mp[ 5 ] = 1 ;
}

int main()
{
    //output ;
    CIN ;
    Extra() ;
    findPrime( 3200 ) ;
    for( ll i = 6 ; i <= 1000000 ; i ++ )
    {
        PrimeFactorization( i ) ;
    }

    ll x ;
    while( cin >> x && x != 0 )
    {
        pf("%lld\n", vec[ x - 1 ] ) ;
        //cout << vec[ x - 1 ] << endl ;
    }

    return 0 ;
}
