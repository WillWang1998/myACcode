#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL calc(LL n,LL x) {
    LL res=0;
    while(n) {
        res+=n/x;
        n/=x;
    }
    return res;
}
int main() {
    LL n,b;
    cin>>n>>b;
    LL ans=-1;
    for(LL i=2;i*i<=b;i++) {
        if(ans==0) break;
        if(b%i) continue;
        int temp=0;
        while(!(b%i)) {
            temp++;
            b/=i;
        }
        if(ans==-1) ans=calc(n,i)/temp;
        else ans=min(ans,calc(n,i)/temp);
    }
    if(ans!=0&&b>1) {
        if(ans==-1) ans=calc(n,b);
        else ans=min(ans,calc(n,b));
    }
    cout<<ans<<endl;
    return 0;
}
