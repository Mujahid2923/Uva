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
#define          ld                     long double
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
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "No" << endl ;
#define          yes                    cout << "Yes" << endl ;
//#define          endl                   '\n'

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
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

vector < ll > v, v1, v2, v3 ;
vector < pll > vec, vec1, vec2 ;
vector < ll > adj[ 15 ][ 15 ] ;
map < ll, ll > Mp;
map < ll, ll > Mp2;
set < ll > st,st1, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S, S2 ;
multiset < ll > :: iterator it ;

ll level[ 15 ][ 15 ] ;
ll visited[ 15 ][ 15 ] ;
char s[ 15 ][ 15 ] ;
ll row, col, idx ;

bool isValid( ll x, ll y, ll val )
{
    if( x >= 1 && x <= row && y >= 1 && y <= col )
    {
        if( visited[ x ][ y ] == 0 )
        {
            visited[ x ][ y ] = 1 ;
            return true ;
        }
        else if( visited[ x ][ y ] == 1 )
        {
            adj[ x ][ y ].pb( val + 1 ) ;
            return false ;
        }
    }
    return false ;
}

void dfs( ll x, ll y )
{
    if( s[ x ][ y ] == 'W' )
    {
        if( isValid( x, y - 1, level[ x ][ y ] ) )
        {
            adj[ x ][ y - 1 ].pb( level[ x ][ y ] + 1 ) ;
            level[ x ][ y - 1 ] = level[ x ][ y ] + 1 ;
            dfs( x, y - 1 ) ;
        }
    }
    else if( s[ x ][ y ] == 'S' )
    {
        if( isValid( x + 1, y, level[ x ][ y ] ) )
        {
            adj[ x + 1 ][ y ].pb( level[ x ][ y ] + 1 ) ;
            level[ x + 1 ][ y ] = level[ x ][ y ] + 1 ;
            dfs( x + 1, y ) ;
        }

    }
    else if( s[ x ][ y ] == 'E' )
    {
        if( isValid( x, y + 1, level[ x ][ y ] ) )
        {
            adj[ x ][ y + 1 ].pb( level[ x ][ y ] + 1 ) ;
            level[ x ][ y + 1 ] = level[ x ][ y ] + 1 ;
            dfs( x, y + 1 ) ;
        }

    }
    else if( s[ x ][ y ] == 'N' )
    {
        if( isValid( x - 1, y, level[ x ][ y ] ) )
        {
            adj[ x - 1 ][ y ].pb( level[ x ][ y ] + 1 ) ;
            level[ x - 1 ][ y ] = level[ x ][ y ] + 1 ;
            dfs( x - 1, y ) ;
        }
    }
}

int main()
{
    // CIN ;

    while( cin >> row >> col >> idx )
    {
        if( row == 0 && col == 0 && idx == 0 )
            break ;

        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
                cin >> s[ i ][ j ] ;
            }
        }

        visited[ 1 ][ idx ] = 1 ;

        adj[ 1 ][ idx ].pb( 0 ) ;
        dfs( 1, idx ) ;

        ll mx = 0 ;
        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
                //cout << level[ i ][ j ] << " " ;
                mx = max( mx, level[ i ][ j ] ) ;
            }
            // cout << endl ;
        }


        int ck = 0 ;
        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
//                for( int k = 0 ; k < adj[ i ][ j ].size() ; k ++ )
//                {
//                    cout << adj[ i ][ j ][ k ] << " " ;
//                }
//                cout << endl ;
                if( adj[ i ][ j ].size() == 2 )
                {
                    v.pb( adj[ i ][ j ][ 0 ] ) ;
                    v.pb( adj[ i ][ j ][ 1 ] ) ;
                    //cout << adj[ i ][ j ][ 0 ] << " " << adj[ i ][ j ][ 1 ] << endl ;
                    ck = 1 ;
                    break ;
                }
            }
            if( ck == 1 )
            {
                break ;
            }
        }

        if( v.empty() )
        {
            cout << mx + 1 << " step(s) to exit" << endl ;
        }
        else
        {
            cout << v[ 0 ] << " step(s) before a loop of " << v[ 1 ] - v[ 0 ] << " step(s)" << endl ;
        }

        for( int i = 0 ; i < 15 ; i ++ )
        {
            for( int j = 0 ; j < 15 ; j ++ )
            {
                adj[ i ][ j ].clear() ;
            }
        }
        v.clear() ;
        zero( visited ) ;
        zero( level ) ;
    }

    return 0 ;
}



