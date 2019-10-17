#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=1e5+7;
LL c[3][maxn];
int color[maxn];
vector<int> vec[maxn];
vector<int> link;
void dfs(int x,int fa) {
    link.push_back(x);
    for(auto it:vec[x]) {
        if(it==fa)  {
            continue;
        } else {
            dfs(it,x);
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%I64d",&c[0][i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%I64d",&c[1][i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%I64d",&c[2][i]);
    }
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        if(vec[i].size()>2) {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) {
        if(vec[i].size()==1) {
            dfs(i,i);
            break;
        }
    }
    vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    vector<int> _ans;
    LL ans=100000000000001;
    do {
        LL temp=0;
        for(int i=0;i<n;i++) {
            temp+=c[p[i%3]][link[i]];
        }
        if(ans>=temp) {
            ans=temp;
            _ans.clear();
            for(auto it:p) _ans.push_back(it);
        }
    } while(next_permutation(p.begin(),p.end()));
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++) {
        color[link[i]]=_ans[i%3]+1;
    }
    for(int i=1;i<=n;i++) {
        printf("%d%c",color[i]," \n"[i==n]);
    }
    return 0;
}
