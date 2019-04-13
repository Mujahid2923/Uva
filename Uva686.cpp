#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<ll>v;

void findPrime(ll *prime)
{
    ll n=35000;
    memset(prime,0,sizeof prime);

    for(int i=4; i<=n; i+=2)
    {
        prime[i]=1;
    }

    prime[1]=1;

    for(int i=3; i*i<=n; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=2; i*j<=n; j++)
            {
                prime[i*j]=1;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}

int main()
{
    ll prime[35000];
    ll n;
    findPrime(prime);
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            break;
        }
        ll cnt=0;
        for(int i=0; v[i]<=n/2; i++)
        {
            ll x=n-v[i];
            if(prime[x]==0)
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
