#include<bits/stdc++.h>
using namespace std;
using LD=long double;
using pldld=pair<LD,LD>;
pldld point[2505];
LD C[2505][2505];
int main() {
    int n,k;
    LD x,y;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        point[i]=make_pair(x,y);
    }
    C[0][0]=1;
    for(int i=1;i<=2500;i++) {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    LD ans=0;
    for(int i=0;i<n;i++) {
        for(int j=1;j<n-k+2;j++) {
            int _i=(i+j)%n;
            LD temp=-point[i].first*point[_i].second+point[i].second*point[_i].first;
            ans+=temp*C[n-j-1][k-2]/2;
        }
    }
    cout<<fixed<<setprecision(8)<<ans/C[n][k]<<endl;
    return 0;
}
