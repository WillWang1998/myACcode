#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int c[maxn],dp[maxn][maxn];
int dfs(int l,int r) {
    if(l==r) return 0;
    if(dp[l][r]) return dp[l][r];
    if(c[l]==c[r]) return dp[l][r]=1+dfs(l+1,r-1);
    else return dp[l][r]=1+min(dfs(l+1,r),dfs(l,r-1));
}
int main() {
    int n,m,a,_a;
    m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        if(i!=0&&_a!=a) c[++m]=_a;
        _a=a;
    }
    c[++m]=_a;
    printf("%d\n",dfs(1,m));
    return 0;
}
