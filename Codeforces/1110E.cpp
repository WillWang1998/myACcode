#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int c[maxn],t[maxn],_c[maxn],_t[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    for(int i=0;i<n;i++) scanf("%d",&t[i]);
    if(c[0]!=t[0]||c[n-1]!=t[n-1]) {
        puts("No");
        return 0;
    }
    for(int i=1;i<n;i++) {
        _c[i]=c[i]-c[i-1];
        _t[i]=t[i]-t[i-1];
    }
    sort(_c+1,_c+n);
    sort(_t+1,_t+n);
    for(int i=1;i<n;i++)
        if(_c[i]!=_t[i]) {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}
