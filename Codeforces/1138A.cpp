#include<bits/stdc++.h>
using namespace std;
int t[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    vector<int> vec;
    int cnt=1;
    for(int i=2;i<=n;i++) {
        if(t[i]!=t[i-1]) {
            vec.push_back(cnt);
            cnt=1;
        } else
            cnt++;
    }
    vec.push_back(cnt);
    int ans=0;
    for(int i=1;i<vec.size();i++)
        ans=max(ans,min(vec[i-1],vec[i])*2);
    cout<<ans<<endl;
    return 0;
}
