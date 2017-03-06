(Analysis by Mark Gordon)
This problem asks us to repeatedly delete the first occurrence of the string TT from a larger string SS until TT no longer appears in SS. The literal translation of this process looks something like this:

while S.find(T)
  S.erase(S.find(T))
Unfortunately this algorithm is far too slow. Each call to find alone takes O(TS)O(TS) time (assuming the underlying implementation uses basic string matching). Since the loop can repeat at most STST times, it follows this has the runtime O(S2)O(S2). Additionally each erase call takes O(S)O(S) time meaning we spend O(S2T)O(S2T) time doing erase calls which is also too slow for small strings T.

To fix this problem consider building the result string, RR, one character at a time. Whenever the end of RR matches TT we should delete it from RR. Since this deletion is at the end of RR this is just a simple O(1)O(1) resize operation.

Now the main problem is how to determine if the end of RR matches TT efficiently. I will discuss two ways of accomplishing this.

Hashing

The first way is to use hashing to efficiently detect string matches. Hashing is a common technique used to speed up the efficiency of string comparisons. Fellow coach Jonathan Paulson discusses how to use this technique here.
In summary, we can initially compute the hash of TT, H(T)H(T), and additionally compute a rolling hash of the end of RR. It's ok (and preferable) to do a full string comparison in case the hashes match to ensure that the strings really do match. Since they do with high probability we can amortize this against the length of RR that we'll delete.

Using a polynomial hash we can keep track of the hash of every prefix of RR which can be used to quickly reconstruct the hash of the last |T||T| characters of RR making the overall runtime of the algorithm O(S)O(S) in expectation.

Knuth-Morris-Pratt

The other way to solve this problem is to use a modified version of the Knuth-Morris-Pratt algorithm. We add characters to RR until we find a match for TT at which point we remove the last |T||T| characters from RR. To reset the KMP algorithm we only need to remember what state we were in |T||T| characters ago and continue the KMP algorithm from that state.
Here's my hashing-based solution to this problem:

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define HM 1000000007
#define HA 100000007
#define HB 101

/* Given the hash 'h' of string S, computes the hash of S + 'ch'. */
int hext(int h, int ch) {
  return (1ll * h * HA + ch + HB) % HM;
}

int main() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

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
