#include <bits/stdc++.h>
using namespace std;

/// max, min
typedef pair<int64_t, int64_t> T;

T f[100005][20];

T comb(T a, T b) {
  if (a.first < b.first) {
    a.first = b.first;
  }
  if (a.second > b.second) {
    a.second = b.second;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = {f[i - 1][0].first + a[i], f[i - 1][0].second + a[i]};
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 0; i + (1 << k) - 1 <= n; i++) {
      f[i][k] = comb(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
    }
  }
  auto get_min = [&](int l, int r) -> int64_t {
    int k = __lg(r - l + 1);
    // cerr << l << " " << r << " " << k << " " << r - (1 << k) + 1 << endl;
    return min(f[l][k].second, f[r - (1 << k) + 1][k].second);
  };
  auto get_max = [&](int l, int r) -> int64_t {
    int k = __lg(r - l + 1);
    return max(f[l][k].first, f[r - (1 << k) + 1][k].first);
  };
  vector<int> L(n + 1, 0), R(n + 1, 0);
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[stk.back()] <= a[i]) {
      stk.pop_back();
    }
    L[i] = stk.empty() ? 1 : stk.back() + 1;
    stk.emplace_back(i);
  }
  stk.clear();
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() && a[stk.back()] <= a[i]) {
      stk.pop_back();
    }
    R[i] = stk.empty() ? n : stk.back() - 1;
    stk.emplace_back(i);
  }
  int64_t ans = -9e18;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, get_max(i, R[i]) - get_min(L[i] - 1, i - 1) - a[i]);
  }
  cout << ans;
  return 0;
}