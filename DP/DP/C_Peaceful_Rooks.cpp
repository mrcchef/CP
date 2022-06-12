#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,m,f[maxn];
int _find(int x){
    return x==f[x]?x:f[x]=_find(f[x]);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)f[i]=i;
		int ans=0,x,y;
		while(m--){
			cin>>x>>y;
			if(x==y)continue;
			ans++;
            int parx=_find(x);
            int pary=_find(y);
            cout<<x<<" "<<y<<endl;
            cout<<parx<<" "<<pary<<endl;
			if(parx==pary)ans++;
			f[pary]=parx;
		}
		cout<<ans<<endl;
	}
	return 0;
}