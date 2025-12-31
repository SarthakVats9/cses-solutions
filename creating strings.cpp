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
string s;
vector<string>ans;
int cnt[26];
void rec(string rn){
if(rn.size()== s.size()){
	ans.pb(rn);
	return;
}
for(int i=0;i<26;i++) {
	if(cnt[i]>0){
		cnt[i]--;
		rec(rn+(char)('a'+i));
		cnt[i]++;
	}
}
}

void solve() {
    cin >> s;
	for (int i=0;i<s.size();i++) {
	  cnt[s[i] -'a']++; }
      rec("");
    cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++) { 
	    cout<<ans[i]<<endl; }
}

// ==================== MAIN ====================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //buildSPF(); // Precompute

    int t = 1;
    
    while (t--) solve();
}



