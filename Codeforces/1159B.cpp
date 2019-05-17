#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,a;
    scanf("%d",&n);
    double ans=1e9;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a);
        if(i!=1) ans=min(ans,1.0*a/(i-1));
        if(i!=n) ans=min(ans,1.0*a/(n-i));
    }
    printf("%.0f\n",floor(ans));
    return 0;
}
