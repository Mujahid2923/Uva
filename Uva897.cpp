#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>v,t;

void findPrime()
{
    ll n=1000;
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
    vector<string>str;
    for(int i=0; i<v.size(); i++)
    {
        stringstream ss;
        ss<<v[i];
        string s;
        s=ss.str();
        if(s.size()==1)
        {
            str.push_back(s);
        }
        else if(s.size()==2)
        {
            string a="";
            a+=s.at(0);
            a+=s.at(1);
            string b="";
            b+=s.at(1);
            b+=s.at(0);
            str.push_back(a);
            str.push_back(b);
        }
        else
        {
            for(int j=0; j<s.size(); j++)
            {
                string p="";
                p+=s.at(j);
                for(int k=0; k<s.size(); k++)
                {
                    if(j==k)
                    {
                        continue;
                    }
                    else
                    {
                        p+=s.at(k);
                    }

                }
                str.push_back(p);
            }

            for(int j=0; j<s.size(); j++)
            {
                string p="";
                p+=s.at(j);
                for(int k=s.size()-1; k>=0; k--)
                {
                    if(j==k)
                    {
                        continue;
                    }
                    else
                    {
                        p+=s.at(k);
                    }

                }
                str.push_back(p);
            }
        }



        ll cnt=0;
        for(int i=0; i<str.size(); i++)
        {
            stringstream ss2;
            ll x;
            ss2<<str[i];
            ss2>>x;
            if(prime[x]==0)
            {
                cnt++;
            }
        }
        stringstream ss3;
        ll g;
        ss3<<str[0];
        ss3>>g;

        if(cnt==str.size())
        {
            t.push_back(g);
        }
        str.clear();
    }
}

int main()
{
    ll n;
    findPrime();
    while(cin>>n && n!=0)
    {
        if(n>=991 || (n>=7 && n<10) || (n>=97 && n<100))
        {
            cout<<0<<endl;
        }
        else
        {
            for(int i=0; i<t.size(); i++)
            {
                if(t[i]>n)
                {
                    cout<<t[i]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
