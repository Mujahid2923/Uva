#include<bits/stdc++.h>
using namespace std;


int p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection()
{
    double low = 0, high = 1,x;
    while (high-low > 0.00000001)
    {
        x = (low+high)/2;
        if (f(low) * f(x) <= 0)
        {
            high = x;
        }
        else
        {
            low = x;
        }
    }
    return x;
}

int main()
{
    while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        if (f(0) * f(1) > 0)
        {
            cout<<"No solution"<<endl;
        }
        else
        {
            printf("%.4lf\n", bisection());
        }
    }
}
