#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int a[105];
map<pii,int> ans2;
int main() {
    int n;
    ans2[make_pair(1,2)]=3;
    ans2[make_pair(1,3)]=4;
    ans2[make_pair(2,1)]=3;
    ans2[make_pair(3,1)]=4;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    int i=0;
    for(i=0;i+1<n;i++) {
        pii _pii=make_pair(a[i],a[i+1]);
        if(ans2.find(_pii)==ans2.end()) {
            cout<<"Infinite"<<endl;
            return 0;
        }
        ans+=ans2[_pii];
    }
    for(i=0;i+2<n;i++)
        if(a[i]==3&&a[i+1]==1&&a[i+2]==2)
            ans--;
    cout<<"Finite"<<endl;
    cout<<ans<<endl;
    return 0;
}
