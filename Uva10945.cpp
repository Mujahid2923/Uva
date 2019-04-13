#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s=="DONE")
        {
            break;
        }
        string str="";
        transform(s.begin(), s.end(), s.begin(),::tolower);

        string p="";

        for(int i=0; i<s.size(); i++)
        {
            if(s.at(i)=='.' || s.at(i)==',' || s.at(i)=='!' || s.at(i)=='?' || s.at(i)==' ')
            {
                continue;
            }
            else
            {
                str+=s.at(i);
            }
        }

        for(int i=s.size()-1; i>=0; i--)
        {
            if(s.at(i)=='.' || s.at(i)==',' || s.at(i)=='!' || s.at(i)=='?' || s.at(i)==' ')
            {
                continue;
            }
            else
            {
                p+=s.at(i);
            }

        }

        if(str==p)
        {
            cout<<"You won't be eaten!"<<endl;
        }
        else
        {
            cout<<"Uh oh.."<<endl;
        }

    }

    return 0;
}




