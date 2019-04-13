#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>v,p;

void findPrime()
{
    ll n=100000;
    ll prime[n];
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

void divisor(ll n)
{
    for(int i=0; v[i]<=sqrt(n); i++)
    {
        if(n%v[i]==0)
        {
            while(n%v[i]==0)
            {
                n=n/v[i];
                p.push_back(v[i]);
            }
        }
    }
    if(n!=1)
    {
        p.push_back(n);
    }
}

int main()
{
    ll n;
    findPrime();
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            break;
        }
        ll f=n;
        n=abs(n);
        divisor(n);
        cout<<f<<" = ";
        if(f<0)
        {
            cout<<"-1";
            for(ll i=0; i<p.size(); i++)
            {
                cout<<" x "<<p[i];
            }
        }
        else
        {
            for(ll i=0; i<p.size(); i++)
            {
                if(i==0)
                {
                    cout<<p[i];
                }
                else
                {
                    cout<<" x "<<p[i];
                }
            }
        }
        cout<<endl;
        p.clear();
    }
}
