#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=1e5+7;
LL a[maxn],b[maxn],sum_a[maxn],sum_b[maxn];
int main() {
    int n,m;
    LL ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for(int i=1;i<=n;i++)
        sum_a[i]=sum_a[i-1]+a[i];
    for(int i=1;i<=m;i++)
        sum_b[i]=sum_b[i-1]+b[i];
    auto it=lower_bound(b+1,b+1+m,a[n])-b;
    if(it==1) {
        if(b[it]>a[n]) {
            ans+=sum_b[m]-sum_b[1];
            ans+=a[n];
            ans+=sum_a[n-1]*m;
            ans-=a[n-1];
            ans+=b[1];
        } else {
            ans+=sum_b[m];
            ans+=sum_a[n-1]*m;
        }
        printf("%lld\n",ans);
    } else {
        printf("-1\n");
    }
    return 0;
}
