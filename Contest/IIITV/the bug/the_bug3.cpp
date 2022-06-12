#include <bits/stdc++.h>
using namespace std;

class solver
{
    private: 
        int temp;
    public:
        class solvClass
        {
            public:
                double dat;
                int dat1;
                char dat2;
        };
        solvClass d;
        double var2;
        int var1;
        char ch;
};
 
 
class solver2 : private solver
{
    public:
        class solv2Class
        {
            public:
                double data2;
                int data1;
                char data3;
        };
        solv2Class s2;
        double varr1;
        int varr2;
};
 
 
class solver3 : private solver
{
    public:
        class solv3Class
        {
            public:
                double dataa2;
                double dataa1;
                int dataa3;
        };
    
        solv3Class s3;
        double v1;
        double v2;
        double v3;
        int varr2;
        char varr1;
};
 
class solver4 : private solver
{
    public:
        int varrr2;
        char varrr1;
};
 
int main()
{
    int n;
    cin>>n;
 
    // We are supposed to minimize the value of given expression
    int sizeOfSolver=sizeof(solver);
    int sizeOfSolver2=sizeof(solver2);
    int sizeOfSolver3=sizeof(solver3);
    int sizeOfSolver4=sizeof(solver4);

    cout<<sizeof(double)<<" "<<sizeof(int)<<" "<<sizeof(char)<<" "<<endl;
    cout<<sizeOfSolver<<" "<<sizeOfSolver2<<" "<<sizeOfSolver3<<" "<<sizeOfSolver4<<endl;

    int mn = min(min(sizeof(solver), sizeof(solver2)), min(sizeof(solver3), sizeof(solver4)));
    int x = ((n + sizeof(solver3))*mn)+sizeof(solver4);
    cout<<x<<"\n";
 
    return 0;
}
