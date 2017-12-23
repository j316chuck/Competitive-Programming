#include <bits/stdc++.h>
#include <string>
using namespace std;

int solution(int n) {
    if (n < 10) return n;
    vector<int> v;
    while (n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    do{
            std::cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    }

       while(std::next_permutation(v.begin(),v.end()));
}

int main() {
    cout << solution(355);

}
