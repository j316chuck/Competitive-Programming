#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
using namespace std;


std::vector<std::string> split(string s) {
	stringstream ss(s);
	vector<string> frag;
	string t;
	while (ss >> t) frag.push_back(t);
	return frag;
}

//http://www.cplusplus.com/reference/cstring/strtok/
vector<string> split(string s, string del = " ") {
    char *word, *buf, *delim;
    vector<string> frag;
	delim = strdup(del.c_str());
	buf = strdup(s.c_str());
	for (word = strtok(buf, delim); word != NULL ; word = strtok(0, delim)) {
        frag.push_back(string(word));
	}
    free(buf);
    free(delim);
	return frag;
}



int main() {
    freopen("input.in", "r", stdin);
    string line;
    while (getline(cin, line)) {
        vector<string> v = split(line, ",");
        for (string x : v) {
            cout << x ;
        } cout << endl;
        /*string pat = "15";
        cout << line.substr(0, line.find(pat)) << endl;
        cout << line.substr(line.find(pat) + pat.size()) << endl;*/
        /*stringstream ss; //sscanf works like regular scanf can be useful but with spaces and extra stuff is not
        //stringstream also works only well with spaces.
        //char = -'0' often works or atoi/stoi
        //c-style parsing function works best.
        ss << line;
        string a, c; int b;
        ss >> a >> b >> c;
        cout << a << ' ' << b << ' ' << c << endl;*/
    }
}
