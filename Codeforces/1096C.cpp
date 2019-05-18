#include<bits/stdc++.h>
using namespace std;
int main () {
    int t,a;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&a);
        if(a==90) {
            printf("4\n");
        } else if(a<=90) {
            a<<=1;
            int g=__gcd(a,360);
            int n=360/g;
            printf("%d\n",n);
        } else {
            a=(180-a)<<1;
            int g=__gcd(a,360);
            int n=360/g;
            if(a==g) n*=2;
            printf("%d\n",n);
        }
    }
    return 0;
}
