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

long long a[105][105];
int n;
long long sol = 0;

void left() {
	for (int i = 0; i < n; i++) {
		long long prev = -1;
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (prev == -1 && a[i][j]) {
				prev = a[i][j];
				a[i][j] = 0;
			} else if (a[i][j]) {
				if (prev == a[i][j]) {
					a[i][j] = 0;
					a[i][idx] = prev << 1;
					sol += a[i][idx];
					idx++;
					prev = -1;
				} else {
					a[i][idx] = prev;
					prev = a[i][j];
					a[i][j] = 0;
					idx++;
				}
			}
		}
		if (prev != -1)
			a[i][idx] = prev;
	}
}

void right() {
	for (int i = 0; i < n; i++) {
		long long prev = -1;
		int idx = n - 1;
		for (int j = n - 1; j >= 0; j--) {

			if (prev == -1 && a[i][j]) {
				prev = a[i][j];
				a[i][j] = 0;
			} else if (a[i][j]) {
				if (prev == a[i][j]) {
					a[i][j] = 0;
					a[i][idx] = prev << 1;
					sol += a[i][idx];
					idx--;
					prev = -1;
				} else {
					a[i][idx] = prev;
					prev = a[i][j];
					a[i][j] = 0;
					idx--;
				}
			}
		}
		if (prev != -1)
			a[i][idx] = prev;
	}
}

void up() {
	for (int j = 0; j < n; j++) {
		long long prev = -1;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (prev == -1 && a[i][j]) {
				prev = a[i][j];
				a[i][j] = 0;
			} else if (a[i][j]) {
				if (prev == a[i][j]) {
					a[i][j] = 0;
					a[idx][j] = prev << 1;
					sol += a[idx][j];
					idx++;
					prev = -1;
				} else {
					a[idx][j] = prev;
					prev = a[i][j];
					a[i][j] = 0;
					idx++;
				}
			}
		}
		if (prev != -1) {
			a[idx][j] = prev;
		}
	}
}

void down() {
	for (int j = 0; j < n; j++) {
		long long prev = -1;
		int idx = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (prev == -1 && a[i][j]) {
				prev = a[i][j];
				a[i][j] = 0;
			} else if (a[i][j]) {
				if (prev == a[i][j]) {
					a[i][j] = 0;
					a[idx][j] = prev << 1;
					sol += a[idx][j];
					idx--;
					prev = -1;
				} else {
					a[idx][j] = prev;
					prev = a[i][j];
					a[i][j] = 0;
					idx--;
				}
			}
		}
		if (prev != -1) {
			a[idx][j] = prev;
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x, y, num;
		scanf("%d %d %d", &num, &x, &y);
		a[x - 1][y - 1] = 1LL * num;
	}
	int l;
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		char d;
		int x, y, num;
		getchar();
		scanf("%c %d %d %d", &d, &num, &x, &y);
		if (d == 'U')
			up();
		else if (d == 'D')
			down();
		else if (d == 'L')
			left();
		else
			right();
		a[x - 1][y - 1] = 1LL * num;
	}
	cout << sol << endl;
//	printf("%I64d\n", sol);
	return 0;
}

