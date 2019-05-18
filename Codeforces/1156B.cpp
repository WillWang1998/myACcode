#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        map<char,int> cnt;
        cnt.clear();
        for(auto it:s) cnt[it]++;
        if(cnt.size()==1) cout<<s<<endl;
        else if(cnt.size()==2) {
            vector<char> vec;
            for(auto it:cnt) vec.push_back(it.first);
            if(vec[0]+1==vec[1]) cout<<"No answer"<<endl;
            else cout<<s<<endl;
        } else if(cnt.size()==3) {
            vector<char> vec;
            for(auto it:cnt) vec.push_back(it.first);
            if(vec[0]+1==vec[1]&&vec[1]+1==vec[2]) {
                cout<<"No answer"<<endl;
            } else if(vec[0]+1==vec[1]) {
                for(int i=0;i<cnt[vec[0]];i++)
                    cout<<vec[0];
                for(int i=0;i<cnt[vec[2]];i++)
                    cout<<vec[2];
                for(int i=0;i<cnt[vec[1]];i++)
                    cout<<vec[1];
                cout<<endl;
            } else if(vec[1]+1==vec[2]) {
                for(int i=0;i<cnt[vec[2]];i++)
                    cout<<vec[2];
                for(int i=0;i<cnt[vec[0]];i++)
                    cout<<vec[0];
                for(int i=0;i<cnt[vec[1]];i++)
                    cout<<vec[1];
                cout<<endl;
            } else cout<<s<<endl;
        } else {
            string temp="";
            for(auto it:cnt) temp+=it.first;
            swap(temp[0],temp[2]);
            swap(temp[1],temp[2]);
            swap(temp[2],temp[3]);
            string ans=temp.substr(0,4);
            for(int i=0;i+4<temp.size();i++) {
                if(i&1) ans=temp.substr(i+4,1)+ans;
                else ans=ans+temp.substr(i+4,1);
            }
            for(auto it:ans)
                for(int i=0;i<cnt[it];i++)
                    cout<<it;
            cout<<endl;
        }
    }
    return 0;
}
