#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int sum[maxn],a[maxn];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            sum[i]=a[i]^sum[max(0,i-4)];
        int q;
        scanf("%d",&q);
        while(q--) {
            int l,r;
            scanf("%d%d",&l,&r);
            int len=r-l+1;
            int blen=len/2;
            int alen=len-blen;
            int temp=0;
            if(alen%2==1) temp^=sum[l+(alen-1)*2]^sum[max(0,l-4)];
            if(blen%2==1) temp^=sum[l+1+(blen-1)*2]^sum[max(0,l-3)];
            printf("%d\n",temp);
        }
    }
    return 0;
}
