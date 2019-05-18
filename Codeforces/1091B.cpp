#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using LL=long long;
pii A[2005];
int main() {
    int n;
    scanf("%d",&n);
    LL x=0,y=0;
    for(int i=1;i<=2*n;i++) {
        scanf("%d%d",&A[i].first,&A[i].second);
        x+=A[i].first;
        y+=A[i].second;
    }
    printf("%lld %lld\n",x/n,y/n);
    return 0;
}
