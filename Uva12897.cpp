#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    char a,b;
    cin>>t;
    while(t--)
    {
        string s,d="";
        char a,b;
        string st="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n;
        cin>>s>>n;

        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            for(int i=0; i<26; i++)
            {
                if(st[i]==b)
                {
                    st[i]=a;
                }
            }
        }
        int l=s.size();
        for(int i=0; i<l; i++)
        {
            if(s.at(i)=='_')
            {
                d+=s.at(i);
            }
            else
            {
                d+=st[s.at(i)-65];
            }
        }
        cout<<d<<endl;
        d="";
    }
    return 0;
}




