#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int x[maxn];
multiset<int> st;
int main() {
    int n,z;
    scanf("%d%d",&n,&z);
    for(int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        st.insert(x[i]);
    }
    sort(x,x+n);
    int l=0,r=n-1;
    while(l<=r) {
        int mid=(l+r)>>1;
        int _l=lower_bound(x,x+n,x[mid]+z)-x;
        if(_l==n) r=mid-1;
        else l=mid+1;
    }
    int ans=0;
    r=min(r,n/2-1);
    for(int i=r;i>=0;i--) {
        auto it=st.lower_bound(x[i]+z);
        if(it!=st.end()) {
            auto _it=st.end();
            _it--;
            st.erase(_it);
            _it=st.lower_bound(x[i]);
            st.erase(_it);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
