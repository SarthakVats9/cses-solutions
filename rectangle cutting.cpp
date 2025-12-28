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

//logic is ez
//implementation is ez
//read question very carefully
//if one approach doesnt work,,,try to think of all cases

// ==================== SOLVE FUNCTION ====================
void solve() {
    int a , b;                                     //
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9));
    for(int i =1 ; i<=min(a,b);i++){
        dp[i][i]=0;
    }
    for(int i =1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                continue;
            }
            else{
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
                }
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
                }
            }
        }
    }
    cout<<dp[a][b];
}

// ==================== MAIN ====================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //buildSPF(); // Precompute

    int t = 1;
    
    while (t--) solve();
}



