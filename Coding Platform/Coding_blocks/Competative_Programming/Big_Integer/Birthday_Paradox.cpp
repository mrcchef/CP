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

int main() {

    float p;
    cin>>p;
    if(p==100)
    {
        cout<<"366"<<endl;
        return 0;
    }
    p=100-p;
    float days=365,t_days=365;
    float n=1,prob=100;
    while(prob>p)
    {
        days--;
        n++;
        deb(prob);
        prob=prob*(days)/t_days;
    }
    deb(prob);
    cout<<n<<endl;
    // cout<<"Hello World!";
}
