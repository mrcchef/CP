#include <iostream>

using namespace std;
int const Nmax = 1000007;
int freq[Nmax];

void cal(int n)
{
    int i,j,curr_freq=0;
    for(i=1;i<=n;i++)
    {
        curr_freq=(curr_freq*10+1)%n;
        if(curr_freq==0)
        {
            for(j=1;j<=i;j++)
                cout<<1;
            break;
        }
        if(freq[curr_freq]!=0)
        {
            for(j=1;j<=i-freq[curr_freq];j++)
                cout<<1;
            for(j=1;j<=freq[curr_freq];j++)
                cout<<0;
            break;
        }
        freq[curr_freq]=i;
    }
}

int main()
{
    int n;
    cin>>n;
    cal(n);
    return 0;
}
