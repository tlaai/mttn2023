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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = ' ' + s;
  vector<int> pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i] == '0' ? 1 : -1);
  }
  const int MOD = 1e9 + 7;
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (abs(pre[i] - pre[j]) <= k) {
        dp[i] += dp[j];
        if (dp[i] >= MOD) {
          dp[i] -= MOD;
        }
      }
    }
  }
  cout << dp[n];
  return 0;
}