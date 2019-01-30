#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const int MAXN=1e6+7;
const int NUM=30;
const LL G=3;
LL wn[NUM],A[MAXN<<2];
inline LL qpow(LL a,LL x,LL mod){
	a%=mod;
	LL ans=1;
	while(x) {
		if(x&1)
			ans=ans*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return ans;
}
void rader(LL A[],int n) {
    int j=n/2;
    for(int i=1;i<n-1;i++) {
        if(i<j)
            swap(A[i],A[j]);
        int k=n/2;
        while(j>=k) {
            j-=k;
            k>>=1;
        }
        if(j<k)
            j+=k;
    }
}
void NTT(LL *A,int n,int ope) {
    int id=0;
    rader(A,n);
    for(int m=2;m<=n;m<<=1) {
        ++id;
        for(int k=0;k<n;k+=m) {
            LL w=1;
            for(int j=k;j<k+(m>>1);++j) {
                LL t=w*A[j+(m>>1)]%MOD;
                LL u=A[j]%MOD;
                A[j]=u+t;
                A[j+(m>>1)]=u-t;
                if(A[j]>=MOD)
                    A[j]-=MOD;
                if(A[j+(m>>1)]<0)
                    A[j+(m>>1)]+=MOD;
                w=w*wn[id]%MOD;
            }
        }
    }
    if(ope==-1) {
        for(int i=1;i<n/2;i++)
            swap(A[i],A[n-i]);
        LL inv=qpow(n,MOD-2,MOD);
        for(int i=0;i<n;++i)
            A[i]=A[i]*inv%MOD;
    }
}
int main() {
    int n,k;
    for(int i=0;i<NUM;++i)
        wn[i]=qpow(G,(MOD-1)>>i,MOD);
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++) {
        LL _a;
        scanf("%lld",&_a);
        A[_a]=1;
    }
    int len=1;
    while(len<n*5) len<<=1;
    NTT(A,len,1);
    for(int i=0;i<len;++i)
        A[i]=qpow(A[i],n/2,MOD);
    NTT(A,len,-1);
    LL ans=0;
    for(int i=0;i<len;++i)
        ans=(ans+A[i]*A[i])%MOD;
    printf("%lld\n",ans);
    return 0;
}
