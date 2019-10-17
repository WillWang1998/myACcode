#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+7;
int x[maxn],y[maxn],z[maxn];
long long dis[maxn][maxn];
bool vis[maxn];
bool cmp(pair<int,int> a,pair<int,int> b) {
    return dis[a.first][a.second]<dis[b.first][b.second];
}
vector<pair<int,int>> vec;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            dis[i][j]=dis[j][i]=1ll*(x[i]-x[j])*(x[i]-x[j])
                                    +1ll*(y[i]-y[j])*(y[i]-y[j])
                                    +1ll*(z[i]-z[j])*(z[i]-z[j]);
            vec.push_back(make_pair(i,j));
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(auto it:vec) {
        if(!vis[it.first]&&!vis[it.second]) {
            vis[it.first]=vis[it.second]=true;
            printf("%d %d\n",it.first,it.second);
        }
    }
    return 0;
}
