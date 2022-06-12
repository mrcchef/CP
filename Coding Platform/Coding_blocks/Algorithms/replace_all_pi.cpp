#include<iostream>
#include<string>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin>>n;
	while(n--)
	{
		string s,t,k="3.14";
        cin>>s;
		for(ll i=0;i<s.size()-1;i++)
		{
			if(s[i]=='p' && s[i+1]=='i')
			{
				i++;
				t+=k;
			}	
			else
			{
				t+=s[i];
			}
		}
		if(s[s.size()-2]=='p' || s[s.size()-1]!='i')
			t+=s[s.size()-1];
		cout<<t<<endl;
	}
	
	return 0;
}