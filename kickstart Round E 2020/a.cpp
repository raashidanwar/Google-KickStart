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
  int n;
  cin >> n;
  vector <int> a(n);
  for(int &i : a)
    cin >> i;
  vector <int> b;
  for(int i = 1; i < n; i++)
    b.push_back(a[i] - a[i - 1]);
  int ans = 0, cnt = 0;
  for(int i = 0; i < (int)b.size(); i++) {
    cnt++;
    if(i == n - 1 || b[i] != b[i + 1]) {
      ans = max(ans, cnt + 1);
      cnt = 0;
    }
  }
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
