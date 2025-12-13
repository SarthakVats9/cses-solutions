#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// ==================== MACROS ====================
#define ll long long
#define f(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ia(a, n) ll a[n]; f(i, n) cin >> a[i]
#define iv(v, n) vector<ll> v(n); f(i, n) cin >> v[i]

const ll MOD = 1000000007;
const ll INF = 1e18;

// ==================== DEBUG ====================
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << nline;
#else
#define debug(x)
#endif

// ==================== SIEVE: SPF ====================

int N = 1e6;
vector<int> spf(N+1); // smallest prime factor for every number

void buildSPF() {
    for (int i = 2; i <= N; i++) spf[i] = i; // initially assume each number's SPF = itself

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) // not marked yet
                    spf[j] = i;  // i is the smallest prime dividing j
        }
    }
}
int LIS(vector<ll> &a) {
    
int n = a.size();
vector<int> dp; // dp[i] = smallest ending value of an IS of length i+1

for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;  }
 //sort(range.begin(), range.end(), cmp);

//logic is ez
//implementation is ez
//read question very carefully
//if one approach doesnt work,,,try to think of all cases

// ==================== SOLVE FUNCTION ====================

vector<vector<int>>adj;
vector<int>vis;

void dfs(int j){
    
    vis[j]=1;
    for(auto x : adj[j]){
        
        if(vis[x]!=1){
            dfs(x);
            
        }
    }
}



void solve() {
    int n ;
    int m ;
    cin >> n >> m ;
    adj.assign(n,{});
    vis.assign(n,0);
    while(m--){
        int  a;
        int b ;
        cin >> a >> b;
        int x= a-1;
        int y=b-1;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> par(n, -1);
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int a =q.front();
        
        q.pop();
        for(auto x :adj[a]){
            if(vis[x]!=1){
                q.push(x);
                vis[x]=1;
                par[x]=a;
            }
        }
    }
    if (par[n-1] == -1) {
    cout << "IMPOSSIBLE";
    return;
}
    vector<int> ans;
    for (int v = n-1; v != -1; v = par[v]){
        ans.pb(v);
}
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    f(i,ans.size()){
        cout<<ans[i]+1<<' ';    
    }
    
}

// ==================== MAIN ====================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //buildSPF(); // Precompute

    int t = 1;
    
    while (t--) solve();
}

