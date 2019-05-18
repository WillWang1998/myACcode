#include<bits/stdc++.h>
using namespace std;
string c,a;
int main() {
    int n;
    cin>>n;
    cin>>c>>a;
    vector<int> cnt0,cnt1,cnt2,cnt3;
    for(int i=0;i<n;i++) {
        if(c[i]=='0'&&a[i]=='0') cnt0.push_back(i+1);
        else if(c[i]=='1'&&a[i]=='0') cnt1.push_back(i+1);
        else if(c[i]=='0'&&a[i]=='1') cnt2.push_back(i+1);
        else if(c[i]=='1'&&a[i]=='1') cnt3.push_back(i+1);
    }
    int temp=n/2-cnt2.size()-cnt3.size();
    vector<int> vec;
    if(temp<0) {
        if(cnt3.size()<-temp) {
            cout<<"-1"<<endl;
            return 0;
        }
        else {
            for(int i=0;i<-temp;i++) vec.push_back(cnt3[i]);
            int cnt=n/2+temp;
            for(int i=0;i<cnt1.size()&&cnt;i++) {
                vec.push_back(cnt1[i]);
                cnt--;
            }
            for(int i=0;i<cnt2.size()&&cnt;i++) {
                vec.push_back(cnt2[i]);
                cnt--;
            }
            if(cnt&1) {
                cout<<-1<<endl;
                return 0;
            }
            int i=-temp;
            for(;i<cnt3.size()&&i+temp<cnt0.size()&&cnt;i++) {
                cnt-=2;
                vec.push_back(cnt3[i]);
                vec.push_back(cnt0[i+temp]);
            }
        }
    } else {
        if(cnt0.size()<temp) {
            cout<<"-1"<<endl;
            return 0;
        }
        else {
            for(int i=0;i<temp;i++) vec.push_back(cnt0[i]);
            int cnt=n/2-temp;
            for(int i=0;i<cnt1.size()&&cnt;i++) {
                vec.push_back(cnt1[i]);
                cnt--;
            }
            for(int i=0;i<cnt2.size()&&cnt;i++) {
                vec.push_back(cnt2[i]);
                cnt--;
            }
            if(cnt&1) {
                cout<<-1<<endl;
                return 0;
            }
            int i=temp;
            for(;i<cnt3.size()&&i-temp<cnt0.size()&&cnt;i++) {
                cnt-=2;
                vec.push_back(cnt0[i]);
                vec.push_back(cnt3[i-temp]);
            }
        }
    }
    for(auto it:vec) cout<<it<<" ";
    return 0;
}
