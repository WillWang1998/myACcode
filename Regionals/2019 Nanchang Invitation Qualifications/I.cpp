#include<bits/stdc++.h>
#define lson i<<1,l,mid
#define rson i<<1|1,mid+1,r
#define root 1,1,n
using namespace std;
using LL=long long;
const int maxn=5e5+7;
const LL inf=0x3f3f3f3f3f3f3f3f;
int n,le[maxn],ri[maxn],a[maxn];
LL sum[maxn],treeMin[maxn<<2],treeMax[maxn<<2];
void pushUp(int i) {
    treeMin[i]=min(treeMin[i<<1],treeMin[i<<1|1]);
	treeMax[i]=max(treeMax[i<<1],treeMax[i<<1|1]);
}
void build(int i,int l,int r) {
    if(l==r) {
        treeMin[i]=treeMax[i]=sum[l];
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushUp(i);
}
LL queryMin(int L,int R,int i,int l,int r) {
    if(L<=l&&r<=R) return treeMin[i];
    int mid=(l+r)>>1;
    LL ans=inf;
    if(mid>=L) ans=min(ans,queryMin(L,R,lson));
    if(mid<R) ans=min(ans,queryMin(L,R,rson));
    return ans;
}
LL queryMax(int L,int R,int i,int l,int r) {
    if(L<=l&&r<=R) return treeMax[i];
    int mid=(l+r)>>1;
    LL ans=-inf;
    if(mid>=L) ans=max(ans,queryMax(L,R,lson));
    if(mid<R) ans=max(ans,queryMax(L,R,rson));
    return ans;
}
LL solve(int l,int r) {
    stack<int> stk;
    for(int i=1;i<=n;i++) {
        while(!stk.empty()&&a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) le[i]=l+1;
        else le[i]=stk.top()+1;
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i=n;i>=1;i--) {
        while(!stk.empty()&&a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) ri[i]=r-1;
        else ri[i]=stk.top()-1;
        stk.push(i);
    }
    build(root);
    LL ans=0;
    for(int i=2;i<=n-1;i++) {
        if(a[i]>0) ans=max(ans,a[i]*(queryMax(i,ri[i],root)-queryMin(le[i]-1,i-1,root)));
        else ans=max(ans,a[i]*(queryMin(i,ri[i],root)-queryMax(le[i]-1,i-1,root)));
    }
    return ans;
}
int main() {
    LL ans=0;
    scanf("%d",&n);
    for(int i=2;i<=n+1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n+2;i++) sum[i]=sum[i-1]+a[i];
    n+=2;
    printf("%lld\n",solve(1,n));
    return 0;
}