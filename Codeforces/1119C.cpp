#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
int cntx[505],cnty[505];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]!=b[i][j]) {
                cntx[i]++;
            }
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(a[i][j]!=b[i][j]) {
                cnty[j]++;
            }
    bool flag=true;
    for(int i=1;i<=n;i++)
        if(cntx[i]%2)
            flag=false;
    for(int i=1;i<=m;i++)
        if(cnty[i]%2)
            flag=false;
    puts(flag?"Yes":"No");
    return 0;
}
