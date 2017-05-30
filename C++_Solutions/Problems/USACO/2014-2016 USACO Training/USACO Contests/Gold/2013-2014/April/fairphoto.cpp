/*ID: j316chuck
PROG: fairphoto
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

using namespace std;

int N;

class pp{
public:
	int pos, num;
	char c;
	bool operator < (const pp & a) const{
		return a.pos > pos;
	}
};

int main(){
	
	Rd("fairphoto.in");
	Wt("fairphoto.out");

	cin>>N;
	vector<pp> A;
	pp ei;
	int num = 0;
	for(int i = 0; i < N; i++){
		cin>>ei.pos>>ei.c;
		ei.num = 0;
		A.push_back(ei);
	}
	sort(A.begin(), A.end());
	
	for(int i = 0; i < N; i++){
		A[i].c == 'S' ? num-- : num++;
		A[i].num = num;
	}
	
	vector<pii> even;
	vector<pii> odd;
	set<int> st;
	for(int i = N-1; i >= 0; i--){
		if(st.size() == 0 || st.find(A[i].num) == st.end()){
			st.insert(A[i].num);
			pii temp = make_pair(A[i].num, A[i].pos);
			A[i].num % 2 == 0 ? even.push_back(temp) : odd.push_back(temp);
		}
	}

	sort(even.begin(), even.end());
	reverse(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	reverse(odd.begin(), odd.end());

	map<int, int> even_dist;
	map<int, int> odd_dist;
	int m = -1;
	for(int i = 0; i < even.size(); i++){
		m = max(m, even[i].second);
		even_dist[even[i].first] = m;
	} 
	m = -1;
	for(int i = 0; i < odd.size(); i++){
		m = max(m, odd[i].second);
		odd_dist[odd[i].first] = m;
	}
	
	num = 0;
	long long total = 0, d1;
	for(int i = 0; i < A.size(); i++){
		num % 2 == 0 ? d1 = even_dist[num] : d1 = odd_dist[num];
		total = max(total, (long long) d1 - (long long) A[i].pos);
		A[i].c == 'S' ? num-- : num++; 
	}
	cout<<total<<endl;
	return 0;
}


	/*for(int i = 0; i < even.size(); i++){
		cout<<even[i].first<<' '<<even[i].second<<endl;
	}
	for(int i = 0; i < odd.size(); i++){
		cout<<odd[i].first<<' '<<odd[i].second<<endl;
	}*/
	/*for(map<int, int>::iterator mt = even_dist.begin(); mt!=even_dist.end(); mt++){
		cout<<mt->first<<' '<<mt->second<<endl;	
	}*/
	/*for(int i = 0; i < N; i++){
		cout<<A[i].c<<' '<<A[i].num<<' '<<A[i].pos<<endl;
	}*/