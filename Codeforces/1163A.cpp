#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    if(m==0) cout<<1<<endl;
    else if(m<=(n>>1)) cout<<m<<endl;
    else cout<<(n-m)<<endl;
    return 0;
}
