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

const ll oo = 0x3f3f3f3f;
const double eps = 1e-6;
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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int tree[200][200][200];

void update(int idx, int idy, int idz, int val) {
	for (int x = idx; x <= 200; x += LSOne(x)) {
		for (int y = idy; y <= 200; y += LSOne(y)) {
			for (int z = idz; z <= 200; z += LSOne(z)) {
				tree[x][y][z] += val;
			}
		}
	}
}

int query(int idx, int idy, int idz) {
	int sum = 0;
	for (int x = idx; x > 0; x -= LSOne(x)) {
		for (int y = idy; y > 0; y -= LSOne(y)) {
			for (int z = idz; z > 0; z -= LSOne(z)) {
				sum += tree[x][y][z];
			}
		}
	}
	return sum;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	while (1) {
		int type;
		cin >> type;
		if (type == 3)
			break;
		if (type == 1) {
			int x, y, z, val;
			cin >> x >> y >> z >> val;
			x++;
			y++;
			z++;
			update(x, y, z, val);
		} else {
			int x0, y0, z0, x1, y1, z1;
			cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
			x0++;
			y0++;
			z0++;
			x1++;
			y1++;
			z1++;
			cout
					<< query(x1, y1, z1) - query(x0 - 1, y1, z1)
							- query(x1, y0 - 1, z1) - query(x1, y1, z0 - 1)
							+ query(x0 - 1, y0 - 1, z1)
							+ query(x0 - 1, y1, z0 - 1)
							+ query(x1, y0 - 1, z0 - 1)
							- query(x0 - 1, y0 - 1, z0 - 1) << endl;
		}
	}
	return 0;
}

