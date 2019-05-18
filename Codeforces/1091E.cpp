#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int a[maxn];
int main() {
    int n;
    scanf("%d",&n);
    int l=0,r=n;
    int cnt0=0,cntn=0;
    int sum=0,max_a=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]==0) cnt0++;
        else if(a[i]==n) cntn++;
        else max_a=max(max_a,a[i]);
    }
    printf("%d\n",sum);
    r=min(r,n-cnt0);
    l=max(l,cntn);
    if((sum&1)^(l&1)) l++;
    if(l>r) printf("-1\n");
    else {
        for(int i=l;i<=r;i+=2) {
            printf("%d\n",(sum-2ll*n*cntn-i));
            if(((sum-2ll*n*cntn-i)%2==0)
               &&((sum-2ll*n*cntn-i)<=2ll*(n-cntn-cnt0)*(n-cntn-cnt0-1)))
                printf("%d ",i);
        }
    }
    return 0;
}
