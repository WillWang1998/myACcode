#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=(n/2);i++) ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    printf("%lld\n",ans);
    return 0;
}
