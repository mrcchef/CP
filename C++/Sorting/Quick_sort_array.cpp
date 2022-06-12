#include<iostream>
using namespace std;

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void display(int *a,int n=5)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
        j--;
        }while(a[j]>pivot);
        if(i<j)
            swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[l],&a[j]);
    cout<<j<<endl;
    display(a);
    return j;
}

void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}


int main()
{
    int size;
    cout<<"Enter Size:";
    cin>>size;
    int a[size+1];
    cout<<"Enter Data:";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    a[size]=INT16_MAX;
    cout<<"Original Array:";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,0,size);
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}