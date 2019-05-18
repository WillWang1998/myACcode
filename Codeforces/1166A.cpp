#include<bits/stdc++.h>
using namespace std;
string s[105];
int cnt[30];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++) {
		cnt[s[i][0]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++) {
		int temp=cnt[i]/2;
		ans+=temp*(temp-1)/2;
		temp=cnt[i]-temp;
		ans+=temp*(temp-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
