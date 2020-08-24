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

int bit[100001];

void upd(int i, int x) {
  for(; i <= 100000; i += (i & -i))
    bit[i] += x;
}

int qry(int i) {
  int sum = 0;
  for(; i; i -= (i & -i))
    sum += bit[i];
  return sum;
}

void solve() {
  int n, sum = 0;
  cin >> n;
  vector <int> e(n + 1), r(n + 1);
  vector <pair<int, int>> a;
  for(int i = 0; i <= n; i++)
    bit[i] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> e[i] >> r[i];
    a.push_back({e[i] + r[i], i});
    upd(i, e[i]);
    sum += e[i];
  }
  sort(a.begin(), a.end());
  set <int> s;
  int ans = 0, x = n;
  for(int i = 0; i < n; i++) {
    while(!a.empty() && sum < a.back().first) {
      s.insert(a.back().second);
      a.pop_back();
    }
    if(s.empty()) {
      cout << n - (int)a.size() << " " << "INDEFINITELY\n";
      return ;
    }
    int ind = *s.begin();
    if(sum + qry(ind - 1) > ans) {
      x = i;
      ans = sum + qry(ind - 1);
    }
    sum -= e[ind];
    s.erase(s.begin());
    upd(ind, -e[ind]);
  }
  cout << x << " " << ans << "\n";
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
