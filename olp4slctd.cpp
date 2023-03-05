#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int64_t INF = 9e18;

int64_t f[N], g[N];
int64_t ans[N];
vector<pair<int, int>> adj[N];
bool c[N];
int cnt[N];

void dfs(int u, int par = -1) {
  f[u] = c[u] ? 0 : INF;
  g[u] = INF;
  cnt[u] = c[u];
  for (auto [v, w] : adj[u]) {
    if (v == par) {
      continue;
    }
    dfs(v, u);
    cnt[u] += cnt[v];
    if (cnt[v]) {
      f[u] = min(f[u], f[v] + w);
      g[u] = min(g[u], f[v] + w);
    } else {
      f[u] = min(f[u], f[v]);
      g[u] = min(g[u], g[v]);
    }
  }
}

void reroot(int u, int par = -1, int par_w = -1) {
  ans[u] = g[u];
  vector<int64_t> pre = {INF}, suf = {INF};
  vector<pair<int, int>> child = {{0, 0}}; 
  for (auto [v, w] : adj[u]) {
    if (v == par) {
      continue;
    }
    if (cnt[v]) {
      pre.emplace_back(f[v] + w);
      suf.emplace_back(f[v] + w);
    } else {
      pre.emplace_back(f[v]);
      suf.emplace_back(f[v]);
    }
    child.emplace_back(v, w);
  }
  pre.emplace_back(INF);
  suf.emplace_back(INF);
  child.emplace_back(0, 0);
  for (int i = 1; i < pre.size(); i++) {
    pre[i] = min(pre[i], pre[i - 1]);
  }
  for (int i = (int)suf.size() - 2; i >= 0; i--) {
    suf[i] = min(suf[i], suf[i + 1]);
  }
  for (int i = 1; i < (int)child.size() - 1; i++) {
    auto [v, w] = child[i];
    vector<int64_t> saved = {cnt[u], f[u], g[u], cnt[v], f[v], g[v]};
    cnt[u] -= cnt[v];
    f[u] = min(pre[i - 1], suf[i + 1]);
    if (par != -1 && cnt[par]) {
      f[u] = min(f[u], f[par] + par_w);
    }
    g[u] = f[u];
    if (c[u]) {
      f[u] = 0;
    }
    cnt[v] += cnt[u];
    f[v] = min(f[v], f[u] + w);
    g[v] = min(g[v], f[u] + w);
    reroot(v, u, w);
    cnt[u] = saved[0];
    f[u] = saved[1];
    g[u] = saved[2];
    cnt[v] = saved[3];
    f[v] = saved[4];
    g[v] = saved[5];
  }
}

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
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  while (k--) {
    int u;
    cin >> u;
    c[u] = 1;
  }
  dfs(1);
  reroot(1);
  for (int u = 1; u <= n; u++) {
    cout << ans[u] << " ";
  }
  return 0;
}
