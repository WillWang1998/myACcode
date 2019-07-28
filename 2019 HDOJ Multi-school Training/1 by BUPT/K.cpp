#include<bits/stdc++.h>
using namespace std;
template <class T> void read(T &x) {
    static char ch;static bool neg;
    for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
    for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
    x=neg?-x:x;
}
using LL=long long;
const int maxn=10000001;
const int mod=998244353;
int prime[maxn],phi[maxn],ss[maxn],sum[maxn];
inline int getCr(__int128 n) {
   	int l=0,r=10000000;
    while(l<=r) {
        int mid=(l+r)>>1;
        if((__int128)mid*mid*mid>n) r=mid-1;
        else l=mid+1;
    }
    return r;
}
inline void init() {
    ss[1]=sum[1]=phi[1]=1;
    for(LL i=2;i<=10000000;i++) {
        if(!prime[i]) {
            prime[++prime[0]]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=prime[0];j++) {
            int temp=i*prime[j];
            if(temp>10000000) break;
            prime[temp]=1;
            if(i%prime[j]==0) {
                 phi[temp]=phi[i]*prime[j];
                break;
            } else phi[temp]=phi[i]*(prime[j]-1); 
            
        }
        sum[i]=(sum[i-1]+i)%mod;
        ss[i]=(1ll*i*i%mod+ss[i-1])%mod;
    }
}
int f1(int x,__int128 y) {
    int res=0;
    for(LL i=1;i*i<=x;i++) {
        if(x%i!=0) continue;
        res=((res+(y/i)*phi[i])%mod)%mod;
        if(i*i!=x) {
            LL j=x/i;
            res=((res+(y/j)*phi[j])%mod)%mod;
        }
    }
    return res;
}
int main() {
    int t;
    __int128 n;
    read(t);
    init();
    while(t--) {
        read(n);
        int cr=getCr(n);
        int ans=((f1(cr,n)-f1(cr,(__int128)cr*cr*cr-1))%mod+mod)%mod;
        for(int i=1;i<=cr-1;i++) {
            ans=((ans+phi[i]*(3ll*i*ss[(cr-1)/i]%mod+3ll*sum[(cr-1)/i]%mod+(cr-1)/i))%mod)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
