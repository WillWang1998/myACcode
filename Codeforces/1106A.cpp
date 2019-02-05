#include<bits/stdc++.h>
using namespace std;
char m[505][505];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",m[i]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(m[i][j]==m[i-1][j-1]
               &&m[i][j]==m[i+1][j-1]
               &&m[i][j]==m[i+1][j+1]
               &&m[i][j]==m[i-1][j+1]
               &&m[i][j]=='X')
                ans++;
    printf("%d\n",ans);
    return 0;
}
