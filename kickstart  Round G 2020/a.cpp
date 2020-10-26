/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  string s;
  cin >> s;
  int n = s.size(), cnt = 0, ans = 0;
  for (int i = 3; i < n; i++) {
    if (s.substr(i - 3, 4) == "KICK")
      cnt++;
    if (s.substr(i - 3, 5) == "START")
      ans += cnt;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }
}
