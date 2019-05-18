#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int maxn=1e6+7;
LL fac[maxn],pfac[maxn];
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
int main() {
    int n;
    fac[0]=fac[1]=1;
    for(int i=2;i<=1000000;i++)
        fac[i]=fac[i-1]*i%mod;
    pfac[1000000]=qpow(fac[1000000],mod-2);
    for(int i=1000000;i>=1;i--)
        pfac[i-1]=pfac[i]*i%mod;
    cin>>n;
    LL ans=fac[n];
    for(int i=2;i<=n-1;i++)
        ans=(ans+fac[n]*pfac[i]%mod*(i-1)%mod*(n-i)%mod)%mod;
    cout<<ans<<endl;
    return 0;
}
