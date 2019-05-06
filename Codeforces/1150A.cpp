#include<bits/stdc++.h>
using namespace std;
int s[50],b[50],dp[1009];
int main() {
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(s,s+n);
    sort(b,b+m);
    dp[0]=r;
    for(int i=1;i<=r;i++) {
        dp[i]=dp[i-1];
        for(int j=0;j<n&&s[j]<=i;j++)
            dp[i]=max(dp[i],dp[i-s[j]]+(-s[j]+b[m-1]));
    }
    printf("%d\n",*max_element(dp,dp+r+1));
    return 0;
}
