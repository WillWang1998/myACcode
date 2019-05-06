#include<bits/stdc++.h>
using namespace std;
const int maxn=300007;
int a[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(a[1]!=a[n]) {
        printf("%d\n",n-1);
        return 0;
    }
    int l=1,r=1;
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1]) {
            l=i-1;
            break;
        }
    for(int i=n-1;i>=0;i--)
        if(a[i]!=a[i+1]) {
            r=n-i;
            break;
        }
    printf("%d\n",n-min(l,r)-1);
    return 0;
}
