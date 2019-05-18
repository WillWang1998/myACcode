#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int maxn=5005;
struct B {
    int p,r,id;
    B() {}
    B(int _p,int _r,int _id) {
        p=_p;
        r=_r;
        id=_id;
    }
    bool operator < (const B &b) const {
        if(p==b.p) return r<b.r;
        else return p<b.p;
    }
}b[maxn];
struct cmp {
    bool operator ()(const B &a,const B &b) {
        if(a.r==b.r) return a.p>b.p;
        else return a.r>b.r;
    }
};
pii s[maxn];
int p[maxn],r[maxn],ans[maxn];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&s[i].first);
        s[i].second=i;
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d",&r[i]);
        b[i]=B(p[i],r[i],i);
    }
    sort(b+1,b+m+1);
    priority_queue<B,vector<B>,cmp> quu;
    int l=m+1;
    for(int i=n;i>=1;i--) {
        int _l=lower_bound(b+1,b+1+m,B(s[i].first,0,0))-b;
        if(_l<l) {
            for(int j=_l;j<l;j++)
                quu.push(b[j]);
            l=_l;
        }
        if(quu.empty()) {
            puts("impossible");
            return 0;
        } else {
            ans[s[i].second]=quu.top().id;
            quu.pop();
        }
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}
