#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void output(int a[],int l)
{
    for(int i=0;i<l;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void insertion_sort(int a[],int l)
{
    int temp,j;
    for(int i=1;i<l;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void bubble_sort(int a[],int l)
{
    for(int i=0;i<l-1;i++)
        for(int j=0;j<l-i;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

void selection_sort(int a[],int l)
{
    int min;
    for(int i=0;i<l;i++)
    {
        min=i;
        for(int j=i+1;j<l;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        swap(a[i],a[min]);
    }
}

int main()
{
int n;
char ch;
cout<<"Enter Length of array";
cin>>n;
int a[n+1];
for(int i=0;i<n;i++)
    cin>>a[i];
cout<<"Enter a character ";
cin>>ch;
switch(ch)
{
    case 's' :  selection_sort(a,n);
                output(a,n);
                break;
    case 'i' :  insertion_sort(a,n);
                output(a,n);
                break;
    case 'b' :  bubble_sort(a,n);
                output(a,n);
                break;
}
}