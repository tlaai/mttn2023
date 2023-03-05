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
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1, 0);
  int violate = 0;
  int best = n;
  for (int i = 1; i <= n; i++) {
    ++cnt[a[i]];
    violate += cnt[a[i]] == 2;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j <= n) {
      if (violate == 0) {
        best = min(best, j - i + 1);
        break;
      }
      j++;
      if (j <= n) {
        violate -= cnt[a[j]] == 2;
        --cnt[a[j]];
      }
    }
    ++cnt[a[i]];
    violate += cnt[a[i]] == 2;
  }
  cout << best;
  return 0;
}