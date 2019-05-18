#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int cnt[maxn],dp[2][3][3];
int main() {
    int n,a;
    while(scanf("%d",&n)!=EOF) {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            cnt[a]++;
        }
        memset(dp,0xC0,sizeof(dp));
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    for(int t=0;t<3;t++)
                        if(cnt[i]>=j+k+t)
                            dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i&1)^1][t][j]+t+(cnt[i]-j-k-t)/2);
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    dp[(i&1)^1][j][k]=0xc0c0c0c0;
        }
        printf("%d\n",dp[n&1][0][0]);
    }
    return 0;
}
