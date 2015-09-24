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
const double eps = 1e-9;
const ll mod = 1000000007;

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

int have[105][50];
string names[150][2];
int n;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 50; j++) {
			have[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			string s;
			cin >> s;
			names[i][j] = s;
			for (int k = 0; k < sz(s); k++) {
				if (isdigit(s[k])) {
					have[i][s[k] - '0' + 26]++;
				} else {
					have[i][s[k] - 'a']++;
				}
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);

	scanf("%d", &n);
	init();
	int idx = -1, mx = -oo;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int cnt[50];
		for (int j = 0; j < 50; j++)
			cnt[j] = 0;
		for (int j = 0; j < a; j++) {
			string s;
			cin >> s;
			for (int k = 0; k < sz(s); k++) {
				if (isdigit(s[k])) {
					cnt[s[k] - '0' + 26]++;
				} else {
					cnt[s[k] - 'a']++;
				}
			}
		}
		int mi = oo;
		for (int j = 0; j < 50; j++) {
			if (have[i][j]) {
				mi = min(mi, cnt[j] / have[i][j]);
			}
		}
		if (mi == oo)
			mi = 0;
		if (mi > mx) {
			mx = mi;
			idx = i;
		}
	}
	printf("%s %s", names[idx][0].c_str(), names[idx][1].c_str());
	return 0;
}

