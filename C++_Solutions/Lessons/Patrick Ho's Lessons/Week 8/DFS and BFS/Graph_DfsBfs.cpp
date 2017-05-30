/*
ID: peiqistar1
PROG:
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

class node
{
public:
	char name;

	vector<node> children;
};

void DFS(node n)
{
	cout << n.name << ' ';
	int iChild = n.children.size();
	for(int i=0; i<iChild; i++)
		DFS(n.children[i]);
}

int main (int argc, char ** argv)
{
	// make up a tree
	node a,b,c,d,e;
	a.name = 'A';
	b.name = 'B';
	c.name = 'C';
	d.name = 'D';
	e.name = 'E';
	b.children.push_back(d);
	b.children.push_back(e);
	a.children.push_back(b);
	a.children.push_back(c);

	// DFS search using recursion
	cout << "DFS search using recursion" << endl;
	DFS(a);
	cout << "done" << endl;

	// DFS search using iteration
	cout << "DFS search using iteration" << endl;
	stack<node> Stack;
	Stack.push(a);
	while(!Stack.empty())
	{
		node n=Stack.top();
		cout << n.name << ' ';
		Stack.pop();
		int iChild=n.children.size();
		for(int i=iChild-1; i>=0; i--)
			Stack.push(n.children[i]);
	}
	cout << "done" << endl;

	// BFS search
	cout << "BFS search" << endl;
	queue<node> Queue;
	Queue.push(a);
	while(!Queue.empty())
	{
		node n=Queue.front();
		cout << n.name << ' ';
		Queue.pop();
		int iChild=n.children.size();
		for(int i=0; i<iChild; i++)
			Queue.push(n.children[i]);
	}
	cout << "done" << endl;
	return 0;
}


