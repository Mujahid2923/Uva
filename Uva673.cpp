#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    getchar();
    string s;
    while(t--)
    {
        stack<char>st;
        getline(cin,s);

        for(int i=0; i<s.size(); i++)
        {
            if(s.at(i)=='(' || s.at(i)=='[')
            {
                st.push(s.at(i));
            }
            else if(s.at(i)==')')
            {
                if(st.empty() || st.top() !='(')
                {
                    st.push('a');
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if(s.at(i)==']')
            {
                if(st.empty() || st.top() !='[')
                {
                    st.push('a');
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if(st.empty())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
