#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    //http://codeforces.com/blog/entry/11080
    //everything is the same as set
    //you can use s.order_of_key to find the kth element, 0th indexed
    //or you can also check how many elements are strictly less than a certain element.
	//https://opensource.apple.com/source/llvmgcc42/llvmgcc42-2336.9/libstdc++-v3/testsuite/ext/pb_ds/example/trie_prefix_search.cc
	ordered_set<int>  s;
	s.insert(1);
	s.insert(3);
	s.insert(100);
	cout << *s.find_by_order(2) << endl;
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}
