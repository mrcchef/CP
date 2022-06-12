#include<bits/stdc++.h>
using namespace std;

void increase(int len, int wid, int hei, int inc , int &t){
        len=len+inc;
        wid=wid+inc;
        hei=hei+inc;
        t=t+(len*wid*hei);
 
        cout << "Volume :" <<len*wid*hei << "gee"<< t <<endl;
 
    }
 
void decrease(int len, int wid, int hei, int dec, int &t){
        len=len-dec;
        wid=wid-dec;
        hei=hei-dec;
        t=t+(len*wid*hei);
        cout << "Volume :" <<len*wid*hei << "gee"<< t <<endl;
 
    }
 
    int Totalvolume(int l, int w, int h,void** ptr){
        int i;
        void **pptr;
        int **ppptr;
        int tot=0;
        void (*funcptr)(int,int,int,int,int&);
        for(i=0;i<5;i++)
        {
            pptr=&ptr[i];
            ppptr=(int**)pptr;
            if(**ppptr%2==0)
                {
                    funcptr=increase;
                    funcptr(l,w,h,1,tot);
                }
            else
                {
                    funcptr=decrease;
                    funcptr(l,w,h,1,tot);
                }  
        }
        return tot;
    }
 
 
int main(void){
   int length=5;
   int width=5;
   int height=5;
 
    int ptr1[5];
    void *ptr2[5];
    cout << "Enter five numbers :" << endl;  
    for(int i=0;i<5;i++)  
    {  
        cin >> ptr1[i];  
    }  
    for(int i=0;i<5;i++)  
    {  
        ptr2[i]=&ptr1[i];  
    }  
int vol=Totalvolume(length,width,height, ptr2);
    cout << vol*2 << endl;  
 
return 0;
}
