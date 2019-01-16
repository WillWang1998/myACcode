#include<bits/stdc++.h>
using namespace std;
const long double pi=acos(-1.0);
int main() {
    long double n,r;
    cin>>n>>r;
    long double deg=(n-2)*pi/(2*n);
    long double p=cos(deg);
    cout<<fixed<<setprecision(7)<<p*r/(1-p)<<endl;
    return 0;
}
