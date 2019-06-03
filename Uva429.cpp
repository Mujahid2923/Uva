///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

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
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          get_pos(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
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

int n ;
map < string, int > Mp ;
string arr[ 1005 ] ;
int visited[ 1005 ] ;
int level[ 1005 ] ;
int cnt = 0 ;
vector < string > vec ;
char s[ 1005 ] ;

bool isValid( string a, string b )
{
    int cnt = 0 ;
    for( int i = 0 ; i < a.size() ; i ++ )
    {
        if( a[ i ] != b[ i ] )
        {
            cnt ++ ;
        }
    }
    if( cnt == 1 && visited[ Mp[ b ] ] == 0 )
    {
        return true ;
    }

    else
        return false ;
}

int bfs( int s, int d )
{
    zero( visited ) ;
    zero( level ) ;

    queue< int > Q ;
    visited[ s ] = 1 ;
    Q.push( s ) ;
    level[ s ] = 0 ;

    while( !Q.empty() )
    {
        int u = Q.front() ;
        Q .pop() ;

        if( d == u )
        {
            return level[ d ] ;
        }

        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            string a = arr[ u ] ;
            string b = vec[ i ] ;
            if( a.size() == b.size() )
            {
                if( isValid( a, b ) )
                {
                    int v = Mp[ b ] ;
                    visited[ v ] = 1 ;
                    Q.push( v ) ;
                    level[ v ] = level[ u ] + 1 ;
                }
            }
        }
    }
}


int main()
{
    //output ;
    string src, des ;
    cin >> n ;
    getchar() ;
    for( int i = 0 ; i < n ; i ++ )
    {
        while( gets( s ) && strcmp( s, "*") )
        {
            Mp[ s ] = cnt ++ ;
            arr[ cnt - 1 ] = s ;

        }

        while( gets( s ) && strlen( s ) )
        {
            char *token ;
            token = strtok( s, " " ) ;
            src = token ;
            token = strtok( NULL, " " ) ;
            des = token ;

            for( auto a : Mp )
            {
                if( a.first.size() == src.size() )
                {
                    vec.pb( a.first ) ;
                }
            }

            int x = bfs( Mp[ src ], Mp[ des ] ) ;
            cout << src << " " << des << " " << x << endl ;
            vec.clear() ;
        }
        if( i != n - 1 )
        {
            cout << "\n" ;
        }
        Mp.clear() ;
        vec.clear() ;
    }
    return 0 ;
}


