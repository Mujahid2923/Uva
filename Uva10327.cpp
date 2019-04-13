#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    while(cin>>n)
    {
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int cnt=0;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(arr[j]>arr[i])
                {
                    cnt++;
                }
            }

        }
        cout<<"Minimum exchange operations : "<<cnt<<endl;
        cnt=0;
    }


    return 0;
}




