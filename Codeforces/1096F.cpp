#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int maxn=2e5+7;
LL fac[maxn];
int p[maxn],b[maxn],pp[maxn],tree[maxn],n;
LL qpow(LL a,LL x) {
    a%=mod;
    LL res=1;
    while(x) {
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
inline int lowbit(int x) {
    return x&(-x);
}
int query(int x) {
    int res=0;
    for(;x>0;x-=lowbit(x))
        res+=tree[x];
    return res;
}
void update(int x,int val) {
    for(;x<=n;x+=lowbit(x))
        tree[x]+=val;
}
int main () {
    fac[0]=fac[1]=1;
    for(int i=2;i<=200000;i++)
        fac[i]=fac[i-1]*i%mod;
    memset(pp,-1,sizeof(pp));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&p[i]);
        if(p[i]!=-1) pp[p[i]]=i;
        b[i]=b[i-1]+(p[i]==-1);
    }
    LL ans=1ll*b[n]*(b[n]-1)%mod*qpow(4,mod-2)%mod;
    LL inv=qpow(b[n],mod-2);
    int cnt=0;
    for(LL i=1;i<=n;i++) {
        if(pp[i]!=-1) {
            int q=query(pp[i]-1);
            ans=(ans+(cnt-q)%mod)%mod;
            ans=(ans+inv*(i-1-cnt)%mod*(b[n]-b[pp[i]])%mod)%mod;
            ans=(ans+inv*(b[n]-i+1+cnt)%mod*b[pp[i]-1]%mod)%mod;
            cnt++;
            update(pp[i],1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
