#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int maxn=105;
int sgn(double x) {
    if(fabs(x)<eps) return 0;
    else if(x<0) return -1;
    else return 1;
}
struct Point {
    double x,y;
    Point() {}
    Point(double _x,double _y):x(_x),y(_y) {}
    Point operator - (const Point &rhs) const {
        return Point(x-rhs.x,y-rhs.y);
    }
    double cross(const Point &rhs) const {
        return x*rhs.y-y*rhs.x;
    }
    double dis (const Point &rhs) const {
        return hypot(x-rhs.x,y-rhs.y);
    }
};
inline bool cmp_x(const Point a, const Point b) {
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
inline vector<Point> andrew(const vector<Point> &point) {
    vector<Point> _point(point);
    sort(_point.begin(),_point.end(),cmp_x);
    int k=0,m=_point.size();
    vector<Point> poly;
    for(int i=0;i<m;i++) {
        while(k>1&&(poly[k-1]-poly[k-2]).cross(_point[i]-poly[k-1])<=0) {
            poly.pop_back();
            k--;
        }
        poly.push_back(_point[i]);
        k++;
    }
    m=k;
    for(int i=point.size()-2;i>=0;i--) {
        while(k>m&&(poly[k-1]-poly[k-2]).cross(_point[i]-poly[k-1])<=0) {
            poly.pop_back();
            k--;
        }
        poly.push_back(_point[i]);
        k++;
    }
    if(k>1) poly.pop_back();
    return poly;
}
inline double calc(const Point &a,const Point &b,const Point &c) {
    return fabs(((b-a).cross(c-a))/(a.dis(b)));
}
int main() {
    int n,x,y;
    scanf("%d",&n);
    vector<Point> vec;
    for(int i=0;i<n;i++) {
        scanf("%d%d",&x,&y);
        vec.push_back(Point(x,y));
    }
    vector<Point> ans=andrew(vec);
    ans.push_back(ans[0]);
    double _ans=2e5;
    for(int i=0;i<ans.size()-1;i++) {
        double temp=-1.0;
        for(int j=0;j<ans.size()-1;j++) {
            temp=max(temp,calc(ans[i],ans[i+1],ans[j]));
        }
        _ans=min(temp,_ans);
    }
    printf("%.6f\n",_ans);
    return 0;
}
