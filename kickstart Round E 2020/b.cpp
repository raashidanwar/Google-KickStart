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


bool check(vector <int> v, int a, int b, int c) {
  for(int i = 0; i < (int)v.size(); i++) {
    int okl = 1, okr = 1;
    for(int j = 0; j < i; j++)
      if(v[j] > v[i])
        okl = 0;
    for(int j = i; j < (int)v.size(); j++)
      if(v[j] > v[i])
        okr = 0;
    a -= okl;
    b -= okr;
    if(okl && okr)
      c--;
  }
  return ((a == 0) & (b == 0) & (c == 0));
}

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector <int> left, right, merge, v;
  for(int i = 0; i < a - 1; i++)
    left.push_back(i + 1);
  for(int i = 0; i < b - 1; i++)
    right.push_back(i + 1);
  merge.push_back(n);
  while((int)left.size() + (int)merge.size() + (int)right.size() > n) {
    if(left.empty() || right.empty()) {
      cout << "IMPOSSIBLE\n";
      return ;
    }
    else {
      merge.push_back(n);
      left.pop_back();
      right.pop_back();
    }
  }
  while(c > (int)merge.size()) {
    if(right.empty() || left.empty()) {
      cout << "IMPOSSIBLE\n";
      return ;
    }
    merge.push_back(n);
    right.pop_back();
    left.pop_back();
  }
  while(!merge.empty()) {
    left.push_back(merge.back());
    merge.pop_back();
  }
  while(!right.empty()) {
    left.push_back(right.back());
    right.pop_back();
  }
  int x = n - int(left.size());
  if(x) {
    for(int i = 0; i < (int)left.size(); i++)
      if(left[i] < n)
        left[i]++;
  }
  for(int i = 0; i < (int)left.size(); i++) {
    v.push_back(left[i]);
    while(x) {
      v.push_back(1);
      x--;
    }
  }
  if(!check(v, a, b, c)) {
    cout << "IMPOSSIBLE\n";
    return ;
  }
  for(int i : v)
    cout << i << " ";
  cout << "\n";
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
