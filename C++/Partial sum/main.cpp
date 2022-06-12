#include <iostream>

using namespace std;
int const Nmax=1000001;
int sum[Nmax],numbers[Nmax];

int main()
{
    int n,i,x,y;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>numbers[i];
    sum[1]=numbers[1];
    for(i=2;i<=n;i++)
        sum[i]=sum[i-1]+numbers[i];
    cin>>x>>y;
    cout<<sum[y]-sum[x-1];

    return 0;
}
