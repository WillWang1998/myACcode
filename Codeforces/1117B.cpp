#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int a[200005];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    LL ans=0;
    LL temp=1ll*k*a[n]+a[n-1];
    ans+=temp*(m/(k+1))+1ll*(m%(k+1))*a[n];
    printf("%lld\n",ans);
    return 0;
}
