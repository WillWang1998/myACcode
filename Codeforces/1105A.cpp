#include<bits/stdc++.h>
using namespace std;
int a[1005];
int ans[105];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int _ans=0;
    for(int i=1;i<=100;i++) {
        for(int j=0;j<n;j++)
            ans[i]+=min(abs(a[j]-i),min(abs(a[j]-i+1),abs(a[j]-i-1)));
        if(_ans==0||ans[i]<=ans[_ans]) _ans=i;
    }
    cout<<_ans<<" "<<ans[_ans]<<endl;
    return 0;
}
