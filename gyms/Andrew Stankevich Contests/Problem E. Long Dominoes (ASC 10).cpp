#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = 1e9 + 1;
const double eps = 1e-7;
const ll mod = 1234567;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).real(),(a).imag())
#define angle(a) atan2((a).imag() , (a).real())
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m) (conj((v)/(m))*m)
#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int m, n;
map<pair<pair<int, int>, string>, ll> memo;

string upd(string msk) {
	for (int i = 0; i < m; i++) {
		if (msk[i] == '1')
			msk[i] = '0';
		else if (msk[i] == '2')
			msk[i] = '1';
		else if (msk[i] == '3')
			msk[i] = '2';
	}
	return msk;
}

ll solve(int i, int j, string msk) {
	if (j == 0)
			msk = upd(msk);
	if (i == n)
		return 1;
	if (memo.find(make_pair(make_pair(i, j), msk)) != memo.end()) {
		return memo[make_pair(make_pair(i, j), msk)];
	}
	if (j == m) {
		return memo[make_pair(make_pair(i, j), msk)] = solve(i + 1, 0, msk);
	}
	bool in  = true;
	ll res = 0;
	if (j + 2 < m && msk[j] == '0' && msk[j + 1] == '0' && msk[j + 2] == '0') {
		string msk1 = msk;
		msk1[j] = '1';
		msk1[j + 1] = '1';
		msk1[j + 2] = '1';
		in = false;
		res += solve(i, j + 3, msk1);
	}
	if (i + 2 < n && msk[j] == '0') {
		string msk2 = msk;
		msk2[j] = '3';
		in = false;
		res += solve(i, j + 1, msk2);
	}
	if (msk[j] != '0' && in) {
		res += solve(i, j + 1, msk);
	}
	return memo[make_pair(make_pair(i, j), msk)] = res;
}

int main() {
	freopen("dominoes.in", "r", stdin);
	freopen("dominoes.out","w",stdout);
	scanf("%d %d", &m, &n);
	string msk = "";
	for (int i = 0; i < m; i++)
		msk += "0";
	memo.clear();
	cout<<solve(0,0,msk)<<endl;
	return 0;
}

