#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int ans[1005][1005];
vector<int> x[1005];
vector<int> y[1005];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            scanf("%d",&a[i][j]);
            x[i].push_back(a[i][j]);
            y[j].push_back(a[i][j]);
        }
    for(int i=1;i<=n;i++) {
        sort(x[i].begin(),x[i].end());
        x[i].resize(unique(x[i].begin(),x[i].end())-x[i].begin());
    }
    for(int i=1;i<=m;i++) {
        sort(y[i].begin(),y[i].end());
        y[i].resize(unique(y[i].begin(),y[i].end())-y[i].begin());
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            int _x=lower_bound(x[i].begin(),x[i].end(),a[i][j])-x[i].begin();
            int _y=lower_bound(y[j].begin(),y[j].end(),a[i][j])-y[j].begin();
            if(_x==_y) ans[i][j]=max(x[i].size(),y[j].size());
            else if(_x<_y) ans[i][j]=max(_y-_x+x[i].size(),y[j].size());
            else ans[i][j]=max(_x-_y+y[j].size(),x[i].size());
            //cout<<i<<" "<<j<<" "<<_x<<" "<<_y<<" "<<ans[i][j]<<endl;
        }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
