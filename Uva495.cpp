#include<bits/stdc++.h>
using namespace std;

vector<string>vs;
vector<int>a,b,c;

void fibonacci()
{
    string p="0";
    string q="1";
    vs.push_back(p);
    vs.push_back(q);

    for(int k=2; k<=5000; k++)
    {
        string a1=vs[k-2];
        string b1=vs[k-1];
        string c1="";

        for(int i=0; i<a1.size(); i++)
        {
            int x=a1[i]-'0';
            a.push_back(x);
        }

        for(int i=0; i<b1.size(); i++)
        {
            int x=b1[i]-'0';
            b.push_back(x);
        }

        if(a.size()<b.size())
        {
            c=a;
            a.clear();
            a.push_back(0);
            for(int i=0; i<c.size(); i++)
            {
                a.push_back(c[i]);
            }

        }

        int ck=0;
        int arr[a.size()];
        for(int i=a.size()-1; i>=0; i--)
        {
            int x=a[i];
            int y=b[i];
            int c;
            if(ck==1)
            {
                c=x+y+1;
                ck=0;
            }
            else
            {
                c=x+y;
            }

            if(i!=0 && c>9)
            {
                c=c%10;
                ck=1;
            }
            arr[i]=c;
        }

        for(int i=0; i<a.size(); i++)
        {
            stringstream ss;
            string s;
            ss<<arr[i];
            s=ss.str();
            c1+=s;
        }
        vs.push_back(c1);
        a.clear();
        b.clear();
        c.clear();
    }
}

int main()
{
    fibonacci();
    int n;
    while(cin>>n)
    {
        cout<<"The Fibonacci number for "<<n<<" is "<<vs[n]<<endl;
    }
    return 0;
}
