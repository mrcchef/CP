//Logic behind the approch is each element of matrix contains sum of all the elements in it's last position of that subarray 


#include<iostream>
using namespace std;
int Sum[100][100];
int main()
{
    int R,C,ri,ci,re,ce,i,j;
    cout<<"Enter Rows and colomns: ";
    cin>>R>>C;
    int p[R+1][C+1];
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            cin>>p[i][j];
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            Sum[i][j]=Sum[i][j-1]+Sum[i-1][j]+p[i][j]-Sum[i-1][j-1]; //Formula
    cout<<"Enter Initial row and Coloumn ";
    cin>>ri>>ci;
    cout<<"Enter FInal ROw and COloumn ";
    cin>>re>>ce;
    cout<<Sum[re][ce]-Sum[ri-1][ce]-Sum[re][ci-1]+Sum[ri-1][ci-1]<<endl; 
    cout<<"Total SUm"<<endl;       
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=C;j++)
            cout<<Sum[i][j]<<" ";
        cout<<endl;
    }
}