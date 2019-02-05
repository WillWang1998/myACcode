#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> vec[maxn];
bool vis[maxn];
void solve() {
    priority_queue<int,vector<int>,greater<int>> quu;
    quu.push(1);
    vis[1]=true;
    while(!quu.empty()) {
        int cur=quu.top();
        quu.pop();
        if(cur!=1) printf(" ");
        printf("%d",cur);
        for(auto it:vec[cur]) {
            if(vis[it]) continue;
            quu.push(it);
            vis[it]=true;
        }
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    solve();
    return 0;
}
