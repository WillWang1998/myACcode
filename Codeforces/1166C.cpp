#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int a[200005];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int p=lower_bound(a,a+n,0)-a;
	LL ans=0;
	for(int i=p;i<n;i++) {
		int temp=lower_bound(a+p,a+i,(a[i]+1)/2)-a;
		ans+=i-temp;
	}
	for(int i=0;i<p;i++) {
		int temp=lower_bound(a,a+p,2*a[i])-a;
		ans+=i-temp;
	}
	for(int i=p;i<n;i++) {
		int q=lower_bound(a,a+p,-a[i])-a;
		int temp1=upper_bound(a+q,a+p,-(a[i]+1)/2)-a;
		int temp2=lower_bound(a,a+q,-2*a[i])-a;
		ans+=temp1-temp2;
	}
	cout<<ans<<endl;
	return 0;
}
