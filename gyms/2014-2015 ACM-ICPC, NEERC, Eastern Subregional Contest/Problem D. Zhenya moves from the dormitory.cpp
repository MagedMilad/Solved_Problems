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

struct Friend {
	double have;
	int adv;
};

struct Room {
	double rent;
	int type, adv;
};

int main() {
//	freopen("in.txt", "r", stdin);
	double have;
	int adv1, adv2;
	scanf("%lf %d %d", &have, &adv1, &adv2);
	int n;
	scanf("%d", &n);
	Friend f[n];
	int mx = -oo;
	int sol_room = -1;
	int sol_friend = -1;
	for (int i = 0; i < n; i++) {
		scanf("%lf %d", &f[i].have, &f[i].adv);
	}
	int m;
	scanf("%d", &m);
	Room r[m];
	for (int i = 0; i < m; i++) {
		scanf("%d %lf %d", &r[i].type, &r[i].rent, &r[i].adv);
	}
	for (int i = 0; i < m; i++) {
		if (have >= r[i].rent) {
			if (r[i].type == 1 && r[i].adv + adv1 > mx) {
				mx = r[i].adv + adv1;
				sol_room = i + 1;
				sol_friend = -1;
			} else if (r[i].type == 2 && r[i].adv + adv2 > mx) {
				mx = r[i].adv + adv2;
				sol_room = i + 1;
				sol_friend = -1;
			}
		}
		for (int j = 0; j < n; j++) {
			if (r[i].type == 2 && have >= r[i].rent / 2.0
					&& f[j].have >= r[i].rent / 2.0) {
				if (r[i].adv + f[j].adv > mx) {
					mx = r[i].adv + f[j].adv;
					sol_room = i + 1;
					sol_friend = j + 1;
				}
			}
		}
	}
	if (sol_friend == -1) {
		if (sol_room == -1) {
			printf("Forget about apartments. Live in the dormitory.\n");
		} else {
			printf("You should rent the apartment #%d alone.\n", sol_room);
		}
	} else {
		printf("You should rent the apartment #%d with the friend #%d.\n",
				sol_room, sol_friend);
	}
	return 0;
}

