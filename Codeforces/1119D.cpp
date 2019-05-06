#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long s[maxn],sum[maxn],d[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
    sort(s+1,s+1+n);
    long long *p=unique(s+1,s+1+n);
    if(p==s+2) {
        int q;
        scanf("%d",&q);
        while(q--) {
            long long l,r,len;
            scanf("%lld%lld",&l,&r);
            len=r-l+1;
            printf("%lld ",len);
        }
    } else {
        n=p-s-1;
        for(int i=1;i<n;i++)
            d[i]=s[i+1]-s[i];
        sort(d+1,d+n);
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+d[i];
        int q;
        scanf("%d",&q);
        while(q--) {
            long long l,r,len;
            scanf("%lld%lld",&l,&r);
            len=r-l+1;
            int pp=upper_bound(d+1,d+n,len)-d;
            printf("%lld ",sum[pp-1]+(n+1-pp)*len);
        }
    }
    return 0;
}
