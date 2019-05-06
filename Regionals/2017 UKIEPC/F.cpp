#include<bits/stdc++.h>
using namespace std;
double dp[404][404];
int main() {
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=1;i<=k;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j]+=dp[i-1][j]*0.5;
            if(j==n) dp[i][j-1]+=dp[i-1][j]*0.5;
            if(j>0) dp[i][j]+=dp[i-1][j-1]*0.5;
        }
    }
    double ans=0;
    for(int i=0;i<=n;i++)
        ans+=dp[k][i]*i;
    cout<<fixed<<setprecision(6)<<ans<<endl;
    return 0;
}
