#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll divisor(ll n)
{
    ll cnt=0;
    ll len=sqrt(n);
    for(ll i=1; i<=len; i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
        }
    }
    return cnt;
}

int main()
{
    vector< pair<ll,ll> >v;
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(ll i=a; i<=b; i++)
        {
            ll x=divisor(i);
            v.push_back(make_pair(i,x));
        }
        ll p,q;
        ll cmp=INT_MIN;
        for(ll i=0; i<v.size(); i++)
        {
            if(v[i].second>cmp)
            {
                cmp=v[i].second;
                p=v[i].first;
                q=v[i].second;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,p,q);
        v.clear();
    }
    return 0;
}
