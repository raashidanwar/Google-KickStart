/* 
  In the name of ALLAH
  Author : Raashid Anwar
  problem : Bundling
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int    int64_t
const int MOD = 1000000007;


int m,k,ans,n;
int node[2000001][26];
int tot[2000001];

void dfs(int u,int d) {
  for(int v=0;v<26;v++) {
    if(node[u][v]) {
      dfs(node[u][v],d+1);
      tot[u]+=tot[node[u][v]];
    }
  }
  ans+=d*(tot[u]/k);
  tot[u]%=k;
}

 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    memset(node,0,sizeof(node));
    memset(tot,0,sizeof(tot));
    m=1;ans=0;
    cin>>n>>k;
    string s;
    for(int i=1;i<=n;i++) {
      cin>>s;
      int u=0;
      for(auto it : s) {
        if(!node[u][it-'A'])
          node[u][it-'A']=m++;
        u=node[u][it-'A'];
      }
      tot[u]++;
    }
    dfs(0,0);
    cout<<"Case #"<<t<<": "<<ans<<"\n";
  }
}
