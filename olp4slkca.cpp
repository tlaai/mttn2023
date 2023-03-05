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
  int a, b, c;
  cin >> a >> b >> c;
  int64_t ans = 0;
  {
    int cur = min(b, a);
    ans += cur;
    b -= cur;
    a -= cur;
  }
  {
    int cur = a / 3;
    ans += cur;
    a %= 3;
  }
  ans += c;
  cout << ans;
  return 0;
}