#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int cnt[55][10005];
int main() {
	int m,n,s,a;
	cin>>m>>n;
	for(int i=0;i<m;i++) {
		cin>>s;
		for(int j=0;j<s;j++) {
			cin>>a;
			cnt[i][a]++;
		}
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<i;j++) {
			int maxCnt=0;
			for(int k=1;k<=n;k++) 
				maxCnt=max(maxCnt,cnt[i][k]+cnt[j][k]);
			if(maxCnt!=2) {
				cout<<"impossible"<<endl;
				return 0;
			}
		}
	}
	cout<<"possible";
	return 0;
}
