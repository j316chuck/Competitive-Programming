#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define HM 1000000007
#define HA 31
#define HB 0

/* Given the hash 'h' of string S, computes the hash of S + 'ch'. */
int hext(int h, int ch) {
  return (1ll * h * HA + ch + HB) % HM;
}

int main() {
  freopen("censor.in", "r", stdin);
  //freopen("censor.out", "w", stdout);

  /* Read the input strings. */
  string S, T;
  cin >> S >> T;

  /* Compute the hash of T. */
  int thsh = 0;
  for (int i = 0; i < T.size(); i++) {
    thsh = hext(thsh, T[i] - 'a');
  }
  /* Build the result string one character a time. */
  string R;
  vector<int> rhsh(1, 0);
  vector<int> HAPW(1, 1);
  for (int i = 0; i < S.size(); i++) {
    /* Update the result string. */
    R += S[i];

    /* Calculate the hash of the new result string. */
    rhsh.push_back(hext(rhsh.back(), S[i] - 'a'));

    /* Calculate the next power of HA. */
    HAPW.push_back((1ll * HAPW.back() * HA) % HM);

    if (R.size() >= T.size()) {
      /* Compute the hash of the last |T| characters of R.  This is done by subtracting out
       * the prefix before the last T characters from the entire hash of R (multiplying by the
       * appropriate power of HA). */
      int hsub = (1ll * rhsh[R.size() - T.size()] * HAPW[T.size()]) % HM;
      int hsh = (HM + rhsh.back() - hsub) % HM;
        cout << hsub <<  ' '  << hsh << endl;
      /* If the end of R and T match truncate the end of R (and associated hash arrays). */
      if (hsh == thsh && R.substr(R.size() - T.size()) == T) {
        R.resize(R.size() - T.size());
        rhsh.resize(rhsh.size() - T.size());
        HAPW.resize(HAPW.size() - T.size());
      }
    }
  }

  cout << R << endl;
  return 0;
}
