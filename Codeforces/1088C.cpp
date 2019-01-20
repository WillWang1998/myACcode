#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",n+1);
    for(int i=n;i>=1;i--) {
        int p=a[i]%(n+1);
        int q=(i-p+n+1)%(n+1);
        printf("1 %d %d\n",i,q);
        for(int j=1;j<=i;j++) {
            a[j]+=q;
        }
    }
    printf("2 %d %d\n",n,n+1);
    return 0;
}
