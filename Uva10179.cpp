///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<iostream>
#include<vector>
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
#define          CASEL(t)               printf("Case %d:\n",t)

///priority_queue<int,vector<int>,greater<int> >pq;

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


vector<int> v,vec;
bool prime[ 100000+5 ];

void findPrime( int n )
{
    for( int i = 0 ; i <= n ; i ++ )
    {
        prime[ i ] = false ;
    }

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

ll phi(ll n)
{
    ll result = n;
    for (int i = 0 ; v[i] * v[i] <= n; i++ )
    {
        if(n % v[i] == 0)
        {
            while(n % v[i] == 0)
            {
                n /= v[i];
            }
            result -= result / v[i] ;
        }
    }

    if(n > 1)
    {
        result -= result / n ;
    }
    return result;
}

int main()
{
    findPrime(100000) ;
    ll n ;

    while( cin >> n && n != 0)
    {
        ll ans = phi(n);
        pf( "%d\n" , ans );
    }

    return 0;
}

