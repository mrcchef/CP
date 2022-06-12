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
#define ll int
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,flag=0,res=0,j;
        cin>>n;
        ll a[n],b[n],mn=INT_MAX;
        map<ll,ll> ma,mb;
        fo(j,n)
        {
            cin>>a[j];
            mn=min(mn,a[j]);
            ma[a[j]]++;
        }
        fo(j,n)
        {
            cin>>b[j];
            mn=min(mn,b[j]);
            mb[b[j]]++;
        }
        vi vb,va;
        ll temp=0;
        for(auto it=ma.begin();it!=ma.end();it++)
        {
            if((it->second)&1)
            {
                if(mb[it->first]&1)
                {
                    ll diff=((mb[it->first])-(it->second))/2;
                    if(diff>0)
                    {
                        while(diff)
                        {
                            vb.pb(it->first);
                            diff--;
                        }
                    }
                    else
                    {
                        diff=abs(diff);
                        while(diff)
                        {
                            va.pb(it->first);
                            diff--;
                        }
                    }
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                if((mb[it->first]&1)==0)
                {
                    ll diff=((mb[it->first])-(it->second))/2;
                    if(diff>0)
                    {
                        while(diff)
                        {
                            vb.pb(it->first);
                            diff--;
                        }
                    }
                    else
                    {
                        diff=abs(diff);
                        while(diff)
                        {
                            va.pb(it->first);
                            diff--;
                        }
                    }
                }
                else
                {
                    flag=1;
                    break;
                }       
            }
        }
        auto it=mb.begin();
        while(it!=mb.end())
        {
            if((it->second&1)==0)
            {
                if((ma[it->first]&1)==0)
                {
                    if(ma[it->first]==0)
                    {
                        temp--;
                        ll diff=(it->second)/2;
                        while(diff)
                        {
                            vb.pb(it->first);
                            diff--;
                        }
                    }
                }
            }
            it++;
        }
        if(va.size()!=vb.size())
            flag=1;
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end(),greater<ll>());
        for(ll i=0;i<va.size();i++)
        {
            res+=min(2*mn,min(va[i],vb[i]));
        }
        cout<<res<<endl;
    }
 return 0;
}
