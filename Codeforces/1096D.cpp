#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
using LL=long long;
char s[maxn];
int a[maxn];
LL dp[maxn][5];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        if(s[i]=='h') {
            dp[i][0]=dp[i-1][0]+a[i];
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
            dp[i][4]=dp[i-1][4];
        } else if(s[i]=='a') {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1]+a[i];
            dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][3]=dp[i-1][3];
            dp[i][4]=dp[i-1][4];
        } else if(s[i]=='r') {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2]+a[i];
            dp[i][3]=min(dp[i-1][2],dp[i-1][3]);
            dp[i][4]=dp[i-1][4];
        } else if(s[i]=='d') {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3]+a[i];
            dp[i][4]=min(dp[i-1][3],dp[i-1][4]);
        }
        else {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
            dp[i][4]=dp[i-1][4];
        }
    }
    printf("%lld\n",min(min(min(dp[n][0],dp[n][1]),dp[n][2]),dp[n][3]));
    return 0;
}
