#include <bits/stdc++.h>
using namespace std;

// DEBUG

#define debug(X) { cerr << #X << " = " << (X) << endl; }
#define debug_arr(X) { cerr << #X << " = "; for(auto e : X) cerr << e << " "; cerr << endl; }
#define debug_func(f,x) { cerr << #f << "(" << (x) << ") = " << (f((x))) << endl; }
#define debug_func2(f,x,y) { cerr << #f << "(" << (x) << "," << (y) << ") = " << (f((x),(y))) << endl; }

template<class T> ostream& print_collection(ostream& s, T const& a){
    s << '[';
    for(auto it = begin(a); it != end(a); ++it){
        s << *it;
        if(it != prev(end(a))) s << " ";
    }
    return s << ']';
}

template<class T, size_t N>
ostream& operator<<(ostream& s, array<T, N> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a) { return s << "(" << (a).first << ", " << (a).second << ")"; }

// MISC.

#define endl '\n'

#define forn(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define foru(i, j, k) for(ll i = (ll)(j); i <= (ll)(k); ++i)
#define ford(i, j, k) for(ll i = (ll)(j); i >= (ll)(k); --i)

#define SQ(x) ((x) * (x))

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

using ll = long long int;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvb = vector<vb>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vti = vector<ti>;
using vtl = vector<tl>;
using ppi = pair<pi, int>;
using ppl = pair<pl, ll>;
template<class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> using max_queue = priority_queue<T>;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF_LL = 1e18;

// END TEMPLATE
// ----------------------------------------------------------------------------


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    #ifndef check_script
        freopen("PB_NAME.in", "r", stdin);
        freopen("PB_NAME.out", "w", stdout);
    #endif



    #ifdef check_script
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
