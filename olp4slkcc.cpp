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
  int n, s;
  cin >> n >> s;
  vector<pair<int, int>> a(n);
  for (auto& [i, c] : a) {
    cin >> i >> c;
  }
  sort(a.begin(), a.end());
  int cnt = 0;
  for (auto [i, c] : a) {
    if (s >= i) {
      ++cnt;
      s += c;
    }
  }
  cout << cnt;
  return 0;
}