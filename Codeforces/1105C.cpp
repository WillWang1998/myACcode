#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL dp[200007][3];
const LL mod=1e9+7;
int main() {
    LL n,l,r;
    cin>>n>>l>>r;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0]=dp[i-1][0]*(r/3-(l-1)/3)%mod;
        dp[i][0]=(dp[i][0]+dp[i-1][1]*((r+1)/3-l/3)%mod)%mod;
        dp[i][0]=(dp[i][0]+dp[i-1][2]*((r+2)/3-(l+1)/3)%mod)%mod;
        dp[i][1]=dp[i-1][1]*(r/3-(l-1)/3)%mod;
        dp[i][1]=(dp[i][1]+dp[i-1][0]*((r+2)/3-(l+1)/3)%mod)%mod;
        dp[i][1]=(dp[i][1]+dp[i-1][2]*((r+1)/3-l/3)%mod)%mod;
        dp[i][2]=dp[i-1][2]*(r/3-(l-1)/3)%mod;
        dp[i][2]=(dp[i][2]+dp[i-1][0]*((r+1)/3-l/3)%mod)%mod;
        dp[i][2]=(dp[i][2]+dp[i-1][1]*((r+2)/3-(l+1)/3)%mod)%mod;
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
