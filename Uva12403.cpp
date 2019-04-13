#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,a,e;
    cin>>t;
    vector<int>v;
    for(int i=1; i<=t; i++)
    {
        cin>>e;
        int sum=0;
        while(e--)
        {
            string s;
            cin>>s;
            if(s=="donate")
            {
                cin>>a;
                sum+=a;
            }
            else
            {
                v.push_back(sum);
            }
        }
        printf("Case %d:\n",i);
        for(int j=0; j<v.size(); j++)
        {
            printf("%d\n",v[j]);
        }
        v.clear();
    }
    return 0;
}


