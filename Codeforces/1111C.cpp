#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int n,k,A,B;
vector<LL> vec;
LL dp(LL l,LL r) {
    LL mid=(l+r)>>1;
    LL cnt=upper_bound(vec.begin(),vec.end(),r)-lower_bound(vec.begin(),vec.end(),l);
    if(cnt==0) return A;
    else if(l==r) return B*cnt;
    else return min(dp(l,mid)+dp(mid+1,r),B*cnt*(r-l+1));
}
int main() {
    scanf("%d%d%d%d",&n,&k,&A,&B);
    LL a;
    for(int i=0;i<k;i++) {
        scanf("%lld",&a);
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    printf("%lld\n",dp(1,1ll<<n));
    return 0;
}
