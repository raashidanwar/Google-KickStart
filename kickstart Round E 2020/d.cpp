/*
  In the name of ALLAH
  Author : Raashid Anwar
  Google Kick Start Round E 2020
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());


void solve() {
  int n, m, s, r;
  cin >> n >> m >> s >> r;
  vector <int> node[n], stones[n], ri_s[s], ri(r), rel(r);
  vector <vector <int>> dp(s, vector <int> (n, M2 * M2));
  for(int i = 0; i < n; i++) {
    node[i].clear();
    stones[i].clear();
  }
  for(int i = 0; i < s; i++) {
    ri_s[i].clear();
  }
  while(m--) {
    int u, v;
    cin >> u >> v;
    node[--u].push_back(--v);
    node[v].push_back(u);
  }
  set <tuple<int, int, int>> si;
  for(int i = 0; i < n; i++) {
    int ci;
    cin >> ci;
    stones[i].resize(ci);
    for(int &st : stones[i]) {
      cin >> st;
      si.insert({0, --st, i});
    }
  }
  for(int i = 0; i < r; i++) {
    cin >> ri[i];
    for(int j = 0; j < ri[i]; j++) {
      int x;
      cin >> x;
      ri_s[--x].push_back(i);
    }
    cin >> rel[i];
    --rel[i];
  }
  map <tuple<int, int>,pair<int, int>> mp;
  while(!si.empty()) {
    int d, st, u;
    tie(d, st, u) = *si.begin();
    si.erase(si.begin());
    if(dp[st][u] <= d)
      continue;
    dp[st][u] = d;
    for(int x : ri_s[st]) {
      mp[{x, u}].first++;
      mp[{x, u}].second += d;
      if(mp[{x, u}].first == ri[x])
        si.insert({mp[{x, u}].second, rel[x], u});
    }
    for(int v : node[u])
      si.insert({d + 1, st, v});
  }
  int ans = M2 * M2;
  for(int i = 0; i < n; i++)
    ans = min(ans, dp[0][i]);
  if(ans >= 100000000000)
    ans = -1;
  cout << ans << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }
}
