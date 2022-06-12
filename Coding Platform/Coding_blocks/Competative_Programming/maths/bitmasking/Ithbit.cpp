#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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

ll getIthbit(ll n,ll i)
{
    return n&(1<<i)!=0?1:0; //TO get any bit we do and operation with that no. here eg. 5:- 101 to get 2nd bit of 5 we need 100 and perform & with 101 
    // we will get 1;
}

void setIthbit(ll &n,ll i)
{
    ll mask=(1<<i);
    n=n|mask; //to perfrom any operation on the same number for some Ith bit we use OR operator such that no other bits get ditrubed. 
}

void clearIthbit(ll &n,ll i)
{
    ll mask=~(1<<i); //101 to delete 2nd bit we need to perform And operation with 011 and to get 011 is ~(100);
    n=n&mask;
}

void updatebit(ll &n,ll i,ll v)
{
    ll mask=~(1<<i); // for updating a bit with 0 or 1 we need to follow 2 step
    ll cleared_n=n&mask; // 1st if we need to update a bit to 0 then simply we have to follw clear Ith Bit concept
    n=cleared_n | (v<<i); // 2nd if we need to update a bit to 1 . eg-  if n= 1011101 and we have to convert 1st bit which is 0 to 1
 }                                                                    //mask= 0000010 and take OR

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,v;
        cin>>n>>i>>v;
        cout<<"Ith bit is:"<<getIthbit(n,i)<<endl;
        setIthbit(n,i);
        cout<<"set Ith bit:"<<n<<endl;
        clearIthbit(n,i);
        cout<<"clear Ith bit:"<<n<<endl;
        updatebit(n,i,v);
        cout<<"Updated value:"<<n<<endl; 
    }
 return 0;
}
