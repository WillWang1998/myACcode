#include<bits/stdc++.h>
using namespace std;
int a[20000],b[20000];
int main() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b[i]=abs(a[i])/2*(a[i]>0?1:-1);
        sum+=b[i];
    }
    for(int i=0;i<n&&sum!=0;i++) {
        if(sum>0&&a[i]<0&&abs(a[i])%2==1) {
            b[i]--;
            sum--;
        } else if(sum<0&&a[i]>0&&abs(a[i])%2==1) {
            b[i]++;
            sum++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<b[i]<<endl;
    return 0;
}
