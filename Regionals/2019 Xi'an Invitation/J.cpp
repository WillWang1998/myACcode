#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=1e5+7;
const LL mod=1e9+7;
int n,fa;
vector<int> vec[maxn];
LL sum[maxn],w[maxn],sz[maxn];
void dfs1(int u) {
    sz[u]=1;
    for(auto it:vec[u]) {
        sum[it]=sum[u]^w[it];
        dfs1(it);
        sz[u]+=sz[it];
    }
}
LL ans=0;
unordered_map<LL,LL> cnt;
void dfs2(int u) {
    ans=(ans+sz[u]*cnt[sum[u]]%mod)%mod;
    for(auto it:vec[u]) {
        cnt[sum[u]]=(cnt[sum[u]]+n-sz[it])%mod;
        dfs2(it);
        cnt[sum[u]]=((cnt[sum[u]]-n+sz[it])%mod+mod)%mod;
    }
    cnt[sum[u]]=(cnt[sum[u]]+sz[u])%mod;
}
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        scanf("%d%lld",&fa,&w[i]);
        vec[fa].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    printf("%lld\n",ans);
    return 0;
}
