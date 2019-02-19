#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    vector<int> vec;
    for(int i=2;i<=n;i++) vec.push_back(b[i]-b[i-1]-1);
    sort(vec.begin(),vec.end());
    int ans=n;
    for(int i=0;i<n-k;i++)
        ans+=vec[i];
    printf("%d\n",ans);
    return 0;
}
