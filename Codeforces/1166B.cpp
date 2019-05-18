#include<bits/stdc++.h>
using namespace std;
string s[5];
string ans[1004];
int main() {
	int n;
	cin>>n;
	s[0]="aeiou";
	for(int i=1;i<5;i++) {
		s[i]=s[0].substr(5-i,i)+s[0].substr(0,5-i);
	}
	for(int i=1;i<=n;i++) {
		if(n%i==0) {
			if(i<5||n/i<5) continue;
			else {
				int _i=n/i;
				for(int p=0;p<i;p+=5) {
					for(int k=0;p+k<i&&k<5;k++) {
						for(int ii=0;ii<_i;ii+=5) {
							for(int j=0;ii+j<_i&&j<5;j++) {
								ans[p+k].push_back(s[k][j]);
							}
						}
					}
				}
				for(int ii=0;ii<i;ii++) cout<<ans[ii];
				return 0;
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
