//#include "contest.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int main(){

    freopen("input.in", "r", stdin);
	float N;
	float sum = 0;
	float counter = 0;
	while(cin>>N) {
		sum+=N;
		counter++;
	}
	int a = (int)(sum)/(int)(counter);
	float b = sum/counter;
	if(b-a == 0.5){
        cout<<a<<' '<<a+1<<endl;
	}else if(b-a > 0.5){
        cout<<a+1<<endl;
	}else{
        cout<<a<<endl;
	}
	exit(0);

}
