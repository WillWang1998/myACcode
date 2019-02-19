#include<bits/stdc++.h>
using namespace std;
int a[100005],dp[100005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int _max=*max_element(a,a+n);
    dp[0]=(a[0]==_max);
    for(int i=1;i<n;i++) dp[i]=(a[i]==_max)?dp[i-1]+1:0;
    printf("%d\n",*max_element(dp,dp+n));
    return 0;
}
