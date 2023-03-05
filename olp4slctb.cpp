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
  int n;
  int64_t m;
  cin >> n >> m;
  vector<int> a(n);

  for (int &i : a) {
    cin >> i;
  }
  int64_t ans = 0;
  while (m > 0) {
    int64_t s = 0;
    int cnt = 0;
    int64_t mm = m;
    for (int i : a) {
      if (mm >= i) {
        s += i;
        mm -= i;
        ++cnt;
      }
    }
    if (s == 0) {
      break;
    }
    ans += 1ll * cnt * (m / s);
    m %= s;
  }
  cout << ans;
  return 0;
}