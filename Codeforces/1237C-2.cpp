#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+7;
int x[3][maxn];
bool vis[maxn];
bool cmp(int a,int b) {
    if(x[0][a]!=x[0][b]) return x[0][a]<x[0][b];
    else if(x[1][a]!=x[1][b]) return x[1][a]<x[1][b];
    else if(x[2][a]!=x[2][b]) return x[2][a]<x[2][b];
}
int vec[maxn];
int solve(int l,int r,int id) {
    if(l>r) return -1;
    if(l==r) return vec[l];
    if(id==0||id==1) {
        int _l=l,_r=r;
        while(l<=r) {
            int mid=(l+r)/2;
            if(x[id][vec[_l]]<x[id][vec[mid]]) r=mid-1;
            else l=mid+1;
        }
        int ans1=solve(_l,r,id+1);
        int ans2=solve(r+1,_r,id);
        if(ans1==-1&&ans2==-1) return -1;
        else if(ans1==-1) return ans2;
        else if(ans2==-1) return ans1;
        else {
            printf("%d %d\n",ans1,ans2);
            return -1;
        }
    } else {
        int i=0;
        for(i=l;i+1<=r;i+=2)
            printf("%d %d\n",vec[i],vec[i+1]);
        if(i==r) return vec[r];
        else return -1;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",&x[0][i],&x[1][i],&x[2][i]);
        vec[i]=i;
    }
    sort(vec+1,vec+n+1,cmp);
    solve(1,n,0);
    return 0;
}
