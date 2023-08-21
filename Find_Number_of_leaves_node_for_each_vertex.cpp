#include <iostream>
#include <vector>
using namespace std;
 
#define ll long long
 
vector<ll> leaf;
 
//call dfs(0, -1, adj) 
//u -> source, p -> parent 
void dfs(ll u, ll p, vector<vector<ll>>& adj) {
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj);
            leaf[u] += leaf[v];
        }
    }
 
    if (leaf[u] == 0) {
        leaf[u] = 1;
    }
}
 