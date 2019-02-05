#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
using LL=long long;
const LL mod0=998244353,mod=998244352;
LL qpow(LL a,LL x,LL _mod) {
    LL res=1;
    while(x) {
        if(x&1) res=res*a%_mod;
        x>>=1;
        a=a*a%_mod;
    }
    return res;
}
struct Matrix {
	LL n,m;
	LL a[maxn][maxn];
	Matrix() {n=m=0;}
    LL* operator[](unsigned id) {return a[id];}
	void clear() {
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix iden() {
		memset(a,0,sizeof(a));
		m=n;
		for(int i=0;i<n;++i)
			a[i][i]=1;
		return *this;
	}
	Matrix operator +(const Matrix &b)const {
		Matrix tmp;
		tmp.n=n;tmp.m=m;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				tmp.a[i][j]=(a[i][j]+b.a[i][j])%mod;
		return tmp;
	}
	Matrix operator *(const Matrix &b)const {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;tmp.m=b.m;
		for(int i=0;i<n;++i)
			for(int j=0;j<b.m;++j)
				for(int k=0;k<m;++k)
					tmp.a[i][j]=((tmp.a[i][j]+((a[i][k])*(b.a[k][j]))%mod)%mod+mod)%mod;
		return tmp;
	}
	Matrix qpow(LL t) {
		Matrix ans=(*this),temp=(*this);
		ans.iden();
		while(t) {
			if(t&1)
				ans=ans*temp;
			t>>=1;
			temp=temp*temp;
		}
		return ans;
	}
	void print() {
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j)
				printf("%lld ",a[i][j]);
			printf("\n");
		}
	}
}A,B,C;
LL BSGS(LL a,LL b,LL _mod) {
    unordered_map<LL,LL> mp;
    if(a%_mod==0) return -1;
    LL m=ceil(sqrt(_mod+0.5));
    LL ans=b%_mod;
    for(int j=0;j<=m;j++) {
        mp[ans]=j;
        ans=ans*a%_mod;
    }
    LL temp=qpow(a,m,_mod);
    ans=temp;
    for(int i=1;i<=m;i++) {
        if(mp.count(ans)) return (i*m)-mp[ans];
        ans=ans*temp%_mod;
    }
    return -1;
}
LL b[maxn];
LL ex_gcd(LL a,LL b,LL &x,LL &y) {
    if(b==0) {
        x=1,y=0;
        return a;
    }
    LL d=ex_gcd(b,a%b,x,y);
    LL t=x;
    x=y,y=t-(a/b)*y;
    return d;
}
int main() {
    int k,n,m;
    scanf("%d",&k);
    for(int i=0;i<k;i++) scanf("%lld",&b[i]);
    scanf("%d%d",&n,&m);
    A.clear();
    A.n=A.m=k;
    for(int i=0;i<k;i++)
        A[0][i]=b[i];
    for(int i=1;i<k;i++)
        A[i][i-1]=1;
    C=A.qpow(n-k);
    LL p=BSGS(3,m,mod0);
    LL x=0,y=0;
    LL d=ex_gcd(C[0][0],mod,x,y);
    if(p%d) printf("-1\n");
    else {
        x=((x*p/d)%mod+mod)%mod;
        printf("%lld\n",qpow(3,x,mod0));
    }
    return 0;
}
