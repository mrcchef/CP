#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printString(char s[22])
{
    for(int i=0;i<strlen(s);i++)
        cout<<s[i];
    cout<<endl;
}

char even(char s[22]){
    char o[15];
    int x=22;
    int len=strlen(s);
    while(len>1){
        int size = 0,index=0;
        for(int i=1;i<len;i+=2){
            o[index]=s[i];
            index++;
        }
        o[index]='\0';
        s=o;
        // printString(s);
        len=index;
    }
    char temp = s[0];
    return temp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    char s[22],a,b;
    

    for(int i=0;i<t;i++){
       cin>>s;
       if(strlen(s)==1)
       {
           cout<<"NO"<<endl;
           continue;
       }
        a = s[0];
        b = even(s);
        cout<<a<<" "<<b<<endl;

        if(a==b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}