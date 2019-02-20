#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        int a=0;
        cin>>s;
        if(s.size()==5)
            cout<<3<<endl;
        else
        {
            if(s[0]=='o')
                a++;
            if(s[1]=='n')
                a++;
            if(s[2]=='e')
                a++;

            if(a>=2)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
    }
    return 0;
}


