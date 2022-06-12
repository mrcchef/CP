#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
using namespace std;
  
  
long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
          //  cout<<x<<endl;
			assert(l<=x && x<=r);
           
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
#define ll long long int 
int main(){
    
    int n,m,k,c,p;
    n = readIntSp(1 , 1e3);
    m = readIntSp(1 , 1e4);
    k = readIntSp(1 , n);
    c = readIntSp(1 , 1e3);
    p = readIntLn(0 , n);
    for(int i=0;i<m;i++){
        int x,y,w;
        x = readIntSp(1 , n);
        y = readIntSp(1 , n);
        assert(x!=y);
        w = readIntLn(1 , 1e5);
    }
    for(int i=0;i<k;i++){
		int val;
		if(i==k-1)
			val=readIntLn(1,n);
		else
        	val = readIntSp(1 , n);
    }
    // c = readIntLn(1 , n);
    for(int i=0;i<p;i++){
		int val;
		if(i==p-1)
			val=readIntLn(1,n);
		else
        	val = readIntSp(1 , n);
    }

	
    // if(p) c = readIntLn(1 , n);
	assert(getchar()==-1); // Ensures that there are no extra characters at the end.
	cerr<<"SUCCESS\n"; // You should see this on the http://campus.codechef.com/files/stderr/SUBMISSION_ID page, at the bottom.
}