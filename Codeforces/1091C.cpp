#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<long long> ans;
    for(int i=1;1ll*i*i<=n;i++) {
        if(n%i==0) {
            int l=n/i;
            ans.push_back((1ll*l*(l-1)/2)*i+l);
            ans.push_back((1ll*i*(i-1)/2)*l+i);
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    for(auto it:ans)
        printf("%lld ",it);
    return 0;
}
