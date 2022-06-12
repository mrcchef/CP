#include<iostream>
using namespace std;

int expo(int n,int m)
{       
    if(m==0)
        return 1;
	else if(m%2==0)
		return expo(n*n,m/2);	
	else
		return expo(n,m-1)*n;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<expo(n,m);
}