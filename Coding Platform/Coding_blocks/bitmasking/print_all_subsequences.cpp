#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
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

void subseq(char in[],char op[],ll i,ll j)
{
    if(in[i]=='\0')
    {
        op[j]='\0';
        cout<<op<<endl;
        return;
    }

    op[j]=in[i];
    subseq(in,op,i+1,j+1);

    op[j]='\0';
    subseq(in,op,i+1,j);
}

int main()
{
    // string s;
    // cin>>s;
    // string op;
    char s[100];
    char op[100];
    cin>>s;
    subseq(s,op,0,0);
    return 0;
}

// Iterative or using bitmasking
// int main()
// {
//     string s;
//     cin>>s;
//     ll sz=s.size();
//     ll sets=1<<sz;
//     for(ll i=1;i<=sets;i++)
//     {
//         ll k=0;
//         for(ll j=i;j>0;j=j>>1)
//         {
//             if(j&1)
//                 cout<<s[k];
//             k++;
//         }
//         cout<<" "<<i;
//         cout<<endl;
//     }
//  return 0;
// }
