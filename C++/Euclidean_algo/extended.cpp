#include<bits/stdc++.h>
using namespace std;

// Only when gcd(a,b) is 1

void EEA(int a,int b,int &x,int &y)
{
    if(a==1)
    {
        x=1;
        y=0;
        return;
    }
    int x1,y1;
    cout<<"a "<<a<<" b "<<b<<endl;
    EEA(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*y;
    
}

int ModInverse(int a,int m)
{
    if(__gcd(a,m)!=1 || a==0 || m==0 ) // __gcd(a,m) is a inbuild funtion to find gcd. time completicy is log(max(a,b)). carefully handle the case for
    {                           // 0,0 and x,0 and 0,x
        return -1;
    }                            
    int x,y;
    EEA(a,m,x,y);
    x=(x%m+m)%m;
    return x;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,m;
        cin>>a>>m;
        int res=ModInverse(a,m);
        if(res==-1)
            cout<<res<<endl;
        else
        {
            cout<<res<<" ";
            cout<<(a*res)%m<<endl;
        }
        
    }
}