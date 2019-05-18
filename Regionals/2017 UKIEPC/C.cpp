#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main() {
    mp["red"]=1;
    mp["yellow"]=2;
    mp["green"]=3;
    mp["brown"]=4;
    mp["blue"]=5;
    mp["pink"]=6;
    mp["black"]=7;
    int n;
    int ans=0;
    cin>>n;
    string s;
    int cnt=0,_max=0,sum=0;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(s=="red") cnt++;
        else {
            _max=max(_max,mp[s]);
            sum+=mp[s];
        }
    }
    if(cnt==n) cout<<1<<endl;
    else cout<<sum+cnt*(1+_max)<<endl;
    return 0;
}
