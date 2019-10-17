#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        bool flag=false;
        for(int i=0;i<=k;i++) {
            if(c*i>=a&&d*(k-i)>=b) {
                cout<<i<<" "<<(k-i)<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
