#include<iostream>
using namespace std;


void merge_array(int a[],int L,int mid,int R)
{
    int i,j,k;
    int smrg[R+1];
    i=L;
    j=mid+1;
    k=0;
    if(a[mid]<=a[mid+1]) // If our array is already sorted
        return;
    while(i<=mid && j<=R)
    {
        if(a[i]<=a[j])
            smrg[k++]=a[i++];
        else 
            smrg[k++]=a[j++];
    }
    while(i<=mid)
        smrg[k++]=a[i++];
    while(j<=R)
        smrg[k++]=a[j++];
    for(i=L;i<=R;i++)
        a[i]=smrg[i-L];
}

void merge_sort(int a[],int L,int R)
{
    if(L==R)
        return;
    int mid=(L+R)/2;
    merge_sort(a,L,mid);
    merge_sort(a,mid+1,R);
    merge_array(a,L,mid,R);  
}
int main()
{
    int n;
    cout<<"Enter Size of Array:";
    cin>>n;
    int a[n];
    cout<<"Enter Elements:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}