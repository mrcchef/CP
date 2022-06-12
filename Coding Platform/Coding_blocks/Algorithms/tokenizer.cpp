// https://hack.codingblocks.com/app/practice/6/1042/problem
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include<string.h>
using namespace std;
#define ll long long int
#define mod (1e9+7)

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
void swap(string &a,string &b){ string t=a; a=b; b=t;}

string extract_keys(string s,ll key)
{
    char *p=strtok((char *)s.c_str()," ");
    while(key>1)
    {
        p=strtok(NULL," ");
    }
    return (string)p;
}

ll convert_to_llint(string s)
{
    ll res=0;
    for(ll i=0;i<s.size();i++)
    {
        res+=s[i]-'0';
        if(i<s.size()-1)
            res=res*10;
    }
    return res;
}

bool numeric_comp(pair<string,string> p1, pair<string,string> p2)
{
    ll x=convert_to_llint(p1.second);
    ll y=convert_to_llint(p2.second);

    return x<y;
}

bool lexico_comp(pair<string,string> p1, pair<string,string> p2)
{
    return p1.second<p2.second;
}

int main()
{
        ll n;
        cin>>n;
        string s[100];
        for(ll i=0;i<n;i++)
            getline(cin,s[i]);
        ll key;
        string reversal,ordering;
        cin>>key;
        cin>>reversal>>ordering;
        pair<string, string> p[100];
        for(ll i=0;i<n;i++)
        {
            p[i].first=s[i];
            p[i].second=extract_keys(s[i],key);
        }
        if(ordering=="numeric")
        {
            sort(p,p+n,numeric_comp);
        }
        else
        {
            sort(p,p+n,lexico_comp);
        }
        if(reversal=="true")
        {
            for(ll i=0;i<n/2;i++)
            {
                swap(s[i],s[n-1-i]);
            }
        }
        for(ll i=0;i<n;i++)
        {
            cout<<p[i].first<<endl;
        }
 return 0;
}
