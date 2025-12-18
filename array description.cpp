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


void solve() {
    int n , m ;
    cin>> n >> m;
    iv(v,n);
    vector<vector<ll>>dp(n,vector<ll>(m+1,0));
    if(v[0]==0){
    for(int j =1; j<=m;j++){
        
            dp[0][j]=1;
        }
    }
    else{
        dp[0][v[0]]=1;
    }
    for(int i =1;i<n;i++){
        if(v[i]==0){
        for(int j =1; j<=m;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(j-1>0){
            dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;}
            if(j+1<=m)
            dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
        }}
        else{
            dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]])%MOD;
           if(v[i]-1>0){
            dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]-1])%MOD;}
            if(v[i]+1<=m)
            dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]+1])%MOD;
        }}
        ll sum=0;
    for(int i =1; i<=m;i++){
        sum=(sum+dp[n-1][i])%MOD;
    }
    cout<<sum<<endl;
}

// ==================== MAIN ====================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //buildSPF(); // Precompute

    int t = 1;
    
    while (t--) solve();
}

