#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main() {
    int n;
    double ans=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]==0) ans+=2;
        else ans+=1.0/a[i];
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    return 0;
}
