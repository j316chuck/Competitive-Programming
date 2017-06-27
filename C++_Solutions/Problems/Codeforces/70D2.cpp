#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define eps 1e-14
using namespace std;

struct point
{
	double x,y,k;
	point(double _x=0,double _y=0) {x=_x,y=_y;}
	bool operator <(const point&B) const {return k-B.k<-eps;}
	friend point operator -(const point&A,const point&B) {return point(A.x-B.x,A.y-B.y);}
	friend double operator *(const point&A,const point&B) {return A.x*B.y-A.y*B.x;}
} O,A,B,C;

ostream &operator << (ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")";
}
int N;
typedef set<point> Set;
typedef Set::iterator it;
Set F;

it pred(it p) {if (p==F.begin()) p=F.end(); return --p;}
it succ(it p) {if (++p==F.end()) p=F.begin(); return p;}

bool ins(const point&p,int f)
{
	it v=F.upper_bound(p),u,k; double t;
	if (v==F.end()) v=F.begin();
	u=pred(v),t=(*u-p)*(*v-p);
	if (f) return t<-eps?0:1; else if (t>-eps) return 0;
	/*cout << "before: ";
	for (auto it = F.begin(); it != F.end(); it++) {
        cout << *it << ' ';
	} cout << endl;*/
	for (;k=pred(u),(*k-*u)*(p-*u)>-eps; u=k) F.erase(u);
	/*cout << "lower: ";
	for (auto it = F.begin(); it != F.end(); it++) {
        cout << *it << ' ';
	} cout << endl;*/
	for (;k=succ(v),(p-*v)*(*k-*v)>-eps; v=k) F.erase(v);
	F.insert(p);
	/*cout << "after: ";
	for (auto it = F.begin(); it != F.end(); it++) {
        cout << *it << ' ';
	} cout << endl;*/
}

int main()
{
    freopen("70D.in", "r", stdin);
	int t;
	scanf("%d%d%lf%lf%d%lf%lf%d%lf%lf",&N,&t,&A.x,&A.y,&t,&B.x,&B.y,&t,&C.x,&C.y),O=point((A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3);
	A.k=atan2(A.y-O.y,A.x-O.x),B.k=atan2(B.y-O.y,B.x-O.x),C.k=atan2(C.y-O.y,C.x-O.x),F.insert(A),F.insert(B),F.insert(C);
	/*for (auto it = F.begin(); it != F.end(); it++) {
        cout << it -> k << endl;
	}*/
	point p;
	for (int i=4,t; i<=N; i++)
	{
		scanf("%d%lf%lf",&t,&p.x,&p.y),p.k=atan2(p.y-O.y,p.x-O.x);
		if (t==1) ins(p,0); else puts(ins(p,1)?"YES":"NO");
	}
}
