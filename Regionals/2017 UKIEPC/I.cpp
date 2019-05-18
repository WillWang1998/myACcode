#include<bits/stdc++.h>
using namespace std;
int h[15],p[15];
int main() {
    int n,T;
    cin>>n;
    for(int i=0;i<n;i++) cin>>h[i];
    cin>>T;
    for(int i=0;i<n;i++) p[i]=T%h[i];
    cout<<h[min_element(p,p+n)-p]<<endl;
    return 0;
}
