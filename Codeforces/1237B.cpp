#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,a[maxn],b[maxn],c[maxn],tree[maxn];
inline int lowbit(int x) {return x&(-x);}
int query(int x) {
    int res;
    for(res=0;x>0;x-=lowbit(x)) {
        res+=tree[x];
    }
    return res;
}
void insert(int x) {
    for(;x<=n;x+=lowbit(x))
        tree[x]++;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        int temp=query(c[b[i]]);
        if(temp!=c[b[i]]-1) {
            ans++;
        }
        insert(c[b[i]]);
    }
    cout<<ans<<endl;
    return 0;
}
