/*ID: j316chuck
PROG: CF_276
LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

/*using namespace std;

int N, Q;
int A[200010];
long long BIT[200010];
long long C[200010];

/*void updateBIT(int index){
    int init = index;
    index = index + (index & -index);
    while(index <= N){
        BIT[init] += BIT[index];
        index += (index & -index);
    }
}*/
/*void update(int index, int val){
    while(index > 0){
        BIT[index] += val;
        index -= (index & -index);
    }
}*/


/*int main(){

    Rd("CF_276.in");
    //Wt("");

    cin>>N>>Q;

    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    int m, p;
    for(int i = 0; i < Q; i++){
        cin>>m>>p;
        BIT[m-1]--;
        BIT[p]++;
        //update(m--, -1);
        //update(p, 1);
    }
    BIT[0] = INT_MAX;
    for(int i = 1; i <= N; i++){
        updateBIT(i);
    }
    for(int i = 0; i <= N; i++){
        cout<<BIT[i]<<endl;
    }
    for(int i = 1; i <= N; i++){

    }
}*/

using namespace std;
long long int a[2000006],n,m,x,y,sayac,i,j,k,t,h[200006],arr[200006];
int main(){
    Rd("CF_276.in");
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);


	for(i=1;i<=m;i++){
		scanf("%lld %lld",&x,&y);
		h[x]++,h[y+1]--;
	}

	for(i=1;i<=n;i++)
		arr[i]=arr[i-1]+h[i];

	sort(arr+1,arr+n+1);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
        cout<<a[i]<<' '<<arr[i]<<endl;
		t+=a[i]*arr[i];
	}
	printf("%lld",t);

	return 0;
}


