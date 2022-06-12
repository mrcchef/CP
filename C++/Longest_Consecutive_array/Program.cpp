#include<iostream>
using namespace std;
const int Nmax=100001;
int fr[Nmax];
int LCA(int p[],int n)
{
    int L,R,ans=0;
    for(L=0;L<n;L++)
    {
        int Max=p[L],Min=p[L];
        for(R=L;R<n;R++)
        {
            if(fr[p[R]]==0)
            {
                fr[p[R]]=1;
            }
            else
                break;
            Max=max(Max,p[R]);
            Min=min(Min,p[R]);
            if(Max-Min+1 == R-L+1)
                ans=(ans,Max-Min+1);

        }
    }
    return ans;
}

int main()
{
    int n,*p,i;
    cout<<"Enter Size of array ";
    cin>>n;
    p=new int[n];
    cout<<"Enter elements ";
    for(i=0;i<n;i++)
        cin>>p[i];
    cout<<LCA(p,n);
}