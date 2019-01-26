#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> vec[maxn],ans;
int n,m,u[maxn],v[maxn],c[maxn],now,seq[maxn];
bool vis[maxn];
void dfs(int x){
    vis[x]=true;
    for(auto it:vec[x])
        if(!vis[it])
            dfs(it);
    seq[x]=++now;
}
bool judge(int lim) {
    for(int i=1;i<=n;i++) vec[i].clear();
    for(int i=0;i<m;i++)
        if(c[i]>lim)
            vec[u[i]].push_back(v[i]);
    now=0;
    memset(vis,false,sizeof(vis));
    memset(seq,0,sizeof(seq));
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=0;i<m;i++)
        if(seq[u[i]]<seq[v[i]])
            if(c[i]>lim)
                return false;
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d%d",&u[i],&v[i],&c[i]);
    int l=0,r=1000000000;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(judge(mid)) r=mid-1;
        else l=mid+1;
    }
    judge(l);
    for(int i=0;i<m;i++)
        if(seq[u[i]]<seq[v[i]]) {
            ans.push_back(i+1);
        }
    printf("%d %d\n",l,ans.size());
    for(auto it:ans)
        printf("%d ",it);
    printf("\n");
    return 0;
}
