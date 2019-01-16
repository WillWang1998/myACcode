#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=k;i++) {
        int e=0,s=0;
        for(int j=1;j<=n;j++)
            b[j]=a[j];
        for(int j=i;j<=n;j+=k)
            b[j]=0;
        for(int j=1;j<=n;j++) {
            if(b[j]==-1) s++;
            else if(b[j]==1) e++;
        }
        ans=max(abs(e-s),ans);
    }
    cout<<ans<<endl;
    return 0;
}
