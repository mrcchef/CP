#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <cstring>
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

// https://online.codingblocks.com/app/player/138764/content/108213/5389/code-challenge
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    ll cnt_s1[256]={0},cnt_s2[256]={0}; // frequency array of both strings
    ll sz1=s1.size();
    ll sz2=s2.size();
    if(sz1<sz2) // if size of main string is less than the other string then we cannot able to find
    {
        cout<<"No String"<<endl;
        return 0;
    }   
     
    for(ll i=0;i<sz2;i++) // Generate a freq. array of s2
    {
        cnt_s2[s2[i]]++;
    }
    ll cnt=0,start=0,window_length,min_len=INT_MAX,min_start=0;;
    for(ll i=0;i<sz1;i++)
    {
        cnt_s1[s1[i]]++; // for every character we generate the freq. array and also check that the freq. of ith character 
        if(cnt_s2[s1[i]]!=0 && cnt_s1[s1[i]]<=cnt_s2[s1[i]]) // if freq. of that charater is non zero in other array and 
        {                                                     // freq of that charater is in main array less than or equal to in other array 
            cnt++;                                             // this means we have found one charater of other array
        }
        // deb(cnt);
        if(cnt==sz2)  // as the we found total no. of charater in main array starting from index start and i i.e it will act as a window,  
        {               // and now we will try to reduce the size of window from start 
            // deb(cnt);
            while(cnt_s1[s1[start]]>cnt_s2[s1[start]] || cnt_s2[s1[start]]==0) // if cnt of start in main array is greater as compared to in other array
            {                                                               // which means we can reduce the size 
                if(cnt_s1[s1[start]]>cnt_s2[s1[start]])
                {
                    cnt_s1[s1[start]]--;  // we  are reducing b/c in uncomping iterations of i we will again check the from line 57;
                }
                start++;        // if already cnt of start is zero in other array then no need to reduce cnt of start in main array but we can increase 
            }                   // start counter b/c we actually not need that character b/c it is not preasent in other array
            window_length=i-start+1; // then we will find the length of window and cal the min len of window
            if(window_length<min_len)
            {
                min_len=window_length;
                min_start=start;   // we will also take care about the index from which the min_len window start
            }
        }
    }
    if(min_len==INT_MAX)    // if min_len is INT_MAX that we have not found any window in which all the characters are present 
    {
        cout<<"No String"<<endl;
    }
    else
    {
        string res=s1.substr(min_start,min_len); // Other wise just cal that substring
        cout<<res<<endl;
    }
    
    
    return 0;
}
