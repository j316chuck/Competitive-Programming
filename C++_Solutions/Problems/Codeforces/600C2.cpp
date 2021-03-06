#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("600C.in", "r", stdin);
	long double P=3.1415926535897932384;
	long double x1,y1,r1,x2,y2,r2,d,alpha,beta,a1,a2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	cout.precision(9);
	if (d>r1+r2) return cout<<0,0;
	if (d<=abs(r2-r1) && r1>=r2) return cout<<P*r2*r2,0;
	if (d<=abs(r2-r1) && r2>=r1) return cout<<P*r1*r1,0;
	alpha=acos((r1*r1+d*d-r2*r2)/(2*r1*d))*2;
	beta=acos((r2*r2+d*d-r1*r1)/(2*r2*d))*2;
	a1=(long double)0.5*beta*r2*r2-0.5*r2*r2*sin(beta);
	a2=(long double)0.5*alpha*r1*r1-0.5*r1*r1*sin(alpha);
	cout<<a1+a2;
}
