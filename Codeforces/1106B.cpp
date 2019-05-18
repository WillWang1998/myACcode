#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=1e5+7;
int a[maxn],c[maxn];
struct Food {
    int c,id;
    bool operator <(Food f) const {
        if(c==f.c) return id<f.id;
        return c<f.c;
    }
};
set<Food> st;
int main() {
    int n,m,t,d;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        st.insert({c[i],i});
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&t,&d);
        Food now=Food({c[t],t});
        if(st.empty()) {
            printf("0\n");
            continue;
        }
        LL ans=0;
        if(a[t]<=d) {
            d-=a[t];
            if(a[t]!=0) st.erase(st.lower_bound({c[t],t}));
            ans+=1ll*a[t]*c[t];
            a[t]=0;
            while(d&&!st.empty()) {
                auto it=st.begin();
                int _id=it->id;
                if(a[_id]>d) {
                    ans+=1ll*d*c[_id];
                    a[_id]-=d;
                    d=0;
                } else {
                    d-=a[_id];
                    ans+=1ll*a[_id]*c[_id];
                    a[_id]=0;
                    st.erase(it);
                }
            }
            if(d!=0) ans=0;
        } else {
            ans+=1ll*d*c[t];
            a[t]-=d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
