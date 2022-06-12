#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
// In this question I did it for only number 2
int main()
{
    string s;
    cin>>s;
    ll a[105],b[105],i;
    a[0]=0;
    fo(i,s.size())
    {
        b[i]=a[i+1]=s[i]-'0';
    }
    ll rem=0,j=1,ja=1,jb=0;
    for(j;j<=s.size();j++)
    {
        if(j==1 && a[j]==1)
        {
            ja=2;
            jb=1;
        }    
        ll val=(rem*10+a[j])/2;
        rem=a[j]%2;
        a[j]=val;
    }
    for(j=1;j<=s.size();j++)
    {
        b[j-1]=a[j];
    }
    i=s.size();
    for(i;i>=0;i--)
    {
        if(a[i]!=9)
        {
            a[i]+=1;
            break;
        }
        a[i]=0;
        if(i==0)
        {
            ja--;
        }
    }
    i=s.size()-1;
    for(i;i>=0;i--)
    {
        if(b[i]!=0)
        {
            b[i]-=1;
            break;
        }
        b[i]=9;
        if(i==0)
        {
            jb++;
        }
    }
    for(ja;ja<=s.size();ja++)
    {
        cout<<a[ja];
    }
    cout<<endl;
    for(jb;jb<s.size();jb++)
    {
        cout<<b[jb];
    }
    cout<<endl;
 return 0;
}
