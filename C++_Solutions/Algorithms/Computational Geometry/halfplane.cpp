//http://www.programering.com/a/MDOxIjNwATg.html
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <complex>
#include <queue>
#define eps 1e-10
#define INF 10000
using namespace std;
typedef complex <double > Point;
typedef pair <Point , Point > Halfplane;
inline double dist(Halfplane hal) {
    return sqrt((hal.second.imag()-hal.first.imag())*(hal.second.imag()-hal.first.imag())+(hal.second.real()-hal.first.real())*(hal.second.real()-hal.first.real()));
}
inline int sgn(double n)
{
    return fabs(n)<eps?0:(n<0?-1:1);
}
inline double cross(Point a,Point b)
{
    return (conj(a)*b).imag();
}
inline double dot(Point a,Point b)
{
    return(conj(a)*b).real();
}
inline double satisfy(Point a,Halfplane p)
{
    return sgn(cross(a-p.first,p.second-p.first))<=0;
}
Point crosspoint (const Halfplane &a,const Halfplane &b)
{
    double k=cross(b.first-b.second,a.first-b.second);
    k=k/(k-cross(b.first-b.second,a.second-b.second));
    return a.first+(a.second-a.first)*k;
}
bool cmp(const Halfplane &a,const Halfplane &b) {
    int res = sgn(arg(a.second-a.first)-arg(b.second-b.first));
    return res == 0 ? satisfy(a.first,b) : res < 0;
}


vector <Point > halfplaneIntersection(vector<Halfplane>v)
{
    sort(v.begin(),v.end(),cmp);
    deque <Halfplane > q;
    deque <Point > ans;
    q.push_back(v[0]);
    for(int i=1; i<int(v.size()); i++)
    {
        if(sgn(arg(v[i].second - v[i].first)-arg(v[i-1].second - v[i-1].first))==0)
            continue;
        while(ans.size()>0 && !satisfy(ans.back(),v[i]))
        {
            ans.pop_back();
            q.pop_back();
        }
        while(ans.size()>0 && !satisfy(ans.front(),v[i]))
        {
            ans.pop_front();
            q.pop_front();
        }
        ans.push_back(crosspoint (q.back(),v[i]));
        q.push_back(v[i]);
    }
    while(ans.size() > 0 && !satisfy(ans.back(),q.front()))
    {
        ans.pop_back();
        q.pop_back();
    }
    while(ans.size() > 0 && !satisfy(ans.front(),q.back()))
    {
        ans.pop_front();
        q.pop_front();
    }
    ans.push_back(crosspoint(q.back(),q.front()));
    return vector <Point > (ans.begin(),ans.end());
}
int main()
{
    int tot;
    while(scanf("%d",&tot))
    {
        vector <Halfplane > pol;
        if(tot==0)
            return 0;
        double fa,fb;
        scanf("%lf%lf",&fa,&fb);
        double la=fa,lb=fb;
        for(int i=1; i<tot; i++)
        {
            double a,b;
            scanf("%lf%lf",&a,&b);
            pol.push_back (Halfplane(Point(la,lb),Point(a,b)));
            la=a,lb=b;
        }
        pol.push_back(Halfplane(Point(la,lb),Point(fa,fb)));
        double l=0,r=20000;
        while(r-l>eps)
        {
            double mid=(l+r)/2.0;
            vector <Halfplane >res;
            vector <Halfplane > ::iterator it;
            for(it=pol.begin(); it!=pol.end(); it++)
            {
                double xx=((*it).first.imag()-(*it).second.imag())/dist((*it))*mid;
                double yy=((*it).second.real()-(*it).first.real())/dist((*it))*mid;
                res.push_back(Halfplane(Point((*it).first.real()+xx,(*it).first.imag()+yy),Point((*it).second.real()+xx,(*it).second.imag()+yy)));
            }
            vector <Point > aa = halfplaneIntersection(res);
            if(aa.size()<3)
                r=mid;
            else l=mid;
        }
        printf("%.6lf\n",(l+r)/2.0);
    }
    return 0;
}
