#include <bits/stdc++.h>
using namespace std;

int SternBrecot(int x, int y) {
    int total = 0;
    while (x && y) {
        if (x > y)  {
            total += (x/y - (y==1));
            x %= y;
        } else {
            total += (y/x - (x==1));
            y %= x;
        }
    }
    return total;
}

/*
//faster and simpler way of writing stern brecot
int calc(int a,int b){
  if(a==1) return b-1;
  if(a==0) return 1<<30;
  return b/a + calc(b%a,a);
}
*/

int main(){
    int x;
	scanf("%d", &x);
	int ans = 1e9;
	for (int i = 1; i <= x; i++) {
        if (__gcd(i, x) != 1) continue;
        ans = min(ans, SternBrecot(x, i));
	}
	printf("%d\n", ans);
	return 0;
}

