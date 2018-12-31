#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int ans=1;
    int _ans=6;
    for(;ans<=100;ans++) {
            if(a[0]>=ans&&a[1]>=ans+1&&a[2]>=ans+2)
               _ans=max(3*ans+3,_ans);
    }
    cout<<_ans<<endl;
    return 0;
}
