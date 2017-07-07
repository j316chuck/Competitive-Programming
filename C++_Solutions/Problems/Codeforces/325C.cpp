#include <bits/stdc++.h>
using namespace std;

int main(){
	long long x,y;
	scanf("%I64d%I64d",&x,&y);
	if (__gcd(x, y) != 1) printf("Impossible\n");
	else {
        while (x && y) {
            if (x > y)  {
                printf("%I64dA", x/y - (y==1));
                x %= y;
            } else {
                printf("%I64dB", y/x - (x==1));
                y %= x;
            }
        }
	}
	return 0;
}
