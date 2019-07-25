///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
///using namespace __gnu_pbds;
///template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


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
#define          min3(a,b,c)            min({a,b,c})
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max({a,b,c})
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;
///string s1 = "abcdefghijklmnopqrstuvwxyz";
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


char s[ 100000 ] ;
vector < ll > v, vec, farabi ;
pair < ll, ll > P[ 100000 ] ;

void findPrime()
{
    int n = 100000 ;
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
            v.pb( i );
        }
    }
}
map < ll, ll > Mp ;
set < ll > st ;
void factorization( ll n )
{
    for( int i = 0 ; v[ i ] * v[ i ] <= n ; i++ )
    {
        int cnt = 0 ;
        while( n % v[ i ] == 0 )
        {
            st.insert( v[ i ] ) ;
            n = n / v[ i ] ;
            cnt ++ ;
        }
        Mp[ v[ i ] ] = cnt ;
    }

    if( n > 1 )
    {
        st.insert( n ) ;
        Mp[ n ] = 1 ;
    }

    for( auto x : st )
    {
        farabi.pb( x ) ;
    }
    reverse( all( farabi ) ) ;
    for( int i = 0 ; i < farabi.size() ; i ++ )
    {
        if( i != farabi.size() - 1 )
        {
            cout << farabi[ i ] << " " << Mp[ farabi[ i ] ] << " " ;
        }
        else
        {
            cout << farabi[ i ] << " " << Mp[ farabi[ i ] ] << endl ;
        }
    }
    farabi.clear() ;
    Mp.clear() ;
    st.clear() ;
}

int main()
{
    //output ;
    CIN ;
    findPrime() ;
    ll val ;
    while( gets( s ) )
    {

        string str ;

        if( s[ 0 ] == '0' )
        {
            break ;
        }
        char *token = strtok( s," " );
        while ( token )
        {
            stringstream ss1 ;
            stringstream ss2 ;
            ss1 << token ;
            ss1 >> str ;
            ss2 << str ;
            ss2 >> val ;
            vec.pb( val ) ;
            token = strtok( NULL," " );
            ss1.clear() ;
            ss2.clear() ;
        }

        int x = 0 ;
        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            if( i % 2 == 0 )
            {
                P[ x ].first = vec[ i ] ;
            }
            else
            {
                P[ x ].second = vec[ i ] ;
                x ++ ;
            }
        }
        ll sum = 1 ;
        for( int i = 0 ; i < x ; i ++ )
        {
            // cout << P[ i ].first << " " << P[ i ].second << endl ;
            ll f = 1 ;
            for( int j = 0 ; j < P[ i ].second ; j ++ )
            {
                f *= P[ i ].first ;
            }
            sum *= f ;
        }

        factorization( sum - 1 ) ;
        vec.clear() ;
    }

    return 0;
}

