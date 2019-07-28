#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],n,q,p,v;
set<int> st;
inline int getAns() {
    if(st.size()&1) return max(n-*st.begin()-1,*st.rbegin());
    else return n;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        st.clear();
        printf("Case #%d:",t);
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if(__builtin_parity(a[i])) st.insert(i);
        }
        while(q--) {
            scanf("%d%d",&p,&v);
            if(__builtin_parity(a[p])) st.erase(p);
            a[p]=v;
            if(__builtin_parity(a[p])) st.insert(p);
            printf(" %d",getAns());
        }
        printf("\n");
    }
    return 0;
}
