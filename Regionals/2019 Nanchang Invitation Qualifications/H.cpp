#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
using LL=long long;
LL qpow(int a,int x) {
    LL res=1;
    while(x) {
        if(x&1) res=res*a%mod;
        x>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
int main() {
    int n;
    scanf("%d",&n);
    if(n==1) printf("1\n");
    else if(n==2) printf("4\n");
    else printf("%lld\n",4ll*qpow(3,n-2)%mod);
    return 0;
}