#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
string s;
int main() {
    cin>>s;
    vector<pii> vec;
    for(int i=0;i<s.length();i++) {
        int temp=i;
        for(int j=i+1;j<s.length();j++) {
            if(s[j]<s[temp]) {
                temp=j;
            }
        }
        if(i!=temp) {
            swap(s[i],s[temp]);
            vec.push_back(make_pair(temp+1,i+1));
        }
    }
    reverse(vec.begin(),vec.end());
    for(auto it:vec) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
