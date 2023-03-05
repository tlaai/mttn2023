#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    while (b > a) {
      if (b % 2) {
        b--;
        if (b % 10) {
          b = -1;
          break;
        }
        b /= 10;
      } else {
        b /= 2;
      }
    }
    cout << (a == b ? "YES" : "NO") << "\n";
  }
  return 0;
}