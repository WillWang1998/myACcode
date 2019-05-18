#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int cnt[maxn],dp[maxn][3][3];
int main() {
    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a);
        cnt[a]++;
    }
    memset(dp,0xC0,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                for(int t=0;t<3;t++)
                    if(cnt[i]>=j+k+t)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][t][j]+t+(cnt[i]-j-k-t)/3);
    printf("%d\n",dp[m][0][0]);
    return 0;
}
