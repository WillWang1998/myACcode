#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const int maxn=105;
struct Matrix {
	LL n,m;
	LL a[maxn][maxn];
	Matrix() {
	    n=m=0;
        memset(a,0,sizeof(a));
	}
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
};
int main() {
    LL n,m;
    cin>>n>>m;
    if(n<m) {
        printf("1\n");
        return 0;
    } else if(n<=2*m-1) {
        printf("%lld\n",(n-m+2)%mod);
        return 0;
    }
    Matrix A;
    A.n=m;
    A.m=1;
    for(int i=0;i<m;i++) A[i][0]=i+2;
    Matrix B;
    B.n=B.m=m;
    for(int i=0;i<m-1;i++) B[i][i+1]=1;
    B[m-1][0]=B[m-1][m-1]=1;
    Matrix C=B.qpow(n-2*m+1);
    Matrix D=C*A;
    printf("%lld\n",D[m-1][0]);
    return 0;
}
