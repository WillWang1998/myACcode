#include<bits/stdc++.h>
using namespace std;
const int maxn=1003;
int a[maxn];
int main() {
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=n;
    for(int i=1;i<=n;i++) {
        sort(a+1,a+i+1,greater<int>());
        long long sum=0;
        bool flag=true;
        for(int j=1;j<=i;j+=2) {
            sum+=a[j];
            if(sum>h) {
                flag=false;
                break;
            }
        }
        if(!flag) {
            ans=i-1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
