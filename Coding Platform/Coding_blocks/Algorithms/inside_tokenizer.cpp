#include <iostream>
#include <string.h>
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

//Here we are going to make our own strtok() function and understand logic behind it.

char* mystrtok(char *str,char del)
{
    static char *input=NULL;
    if(str!=NULL)
    {
        input=str;
    }
    if(input==NULL)
    {
        return NULL;
    }
    
    char *output=new char[strlen(input)+1]; //for storing '\0'
    ll i;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=del)
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    output[i]='\0';
    input=NULL; 
    return output;
       
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char str[]="Hello Abhijeet Tamrakar";
        char *p=mystrtok(str,' ');
        while(p!=NULL)
        {
            cout<<p<<endl;
            p=mystrtok(NULL,' ');
        }
    }
 return 0;
}
