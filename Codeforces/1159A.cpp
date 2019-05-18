#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ans=0;
    for(auto it:s) {
        if(it=='-') ans=max(0,ans-1);
        else ans=ans+1;
    }
    cout<<ans<<endl;
    return 0;
}
