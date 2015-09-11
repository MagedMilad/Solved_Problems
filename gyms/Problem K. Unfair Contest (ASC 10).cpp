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

struct Prob {
	int i, a, l, o;
};

struct Team {
	int t, z, v, c;
};

int ceil(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	freopen("unfair.in","r",stdin);
	freopen("unfair.out","w",stdout);
	int m, n, t, l;
	vector<Prob> prob;
	vector<Team> team;
	scanf("%d %d %d %d", &m, &n, &t, &l);
	prob.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &prob[i].i, &prob[i].a, &prob[i].l, &prob[i].o);
	}
	team.resize(t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d", &team[i].t, &team[i].z, &team[i].v, &team[i].c);
	}
	vector<bool> prob_set(m), ans;
	int mx = t;
	fill(prob_set.begin(), prob_set.begin() + n, true);
	do {
		vector<pair<int, int> > rank;
		for (int j = 0; j < t; j++) {
			vector<pair<int, int> > todo;
			for (int i = 0; i < m; i++) {
				if (!prob_set[i]
						|| team[j].t + team[j].c <= prob[i].i - prob[i].o) {
					continue;
				}
				int eij = ceil(prob[i].i, prob[i].o)
						+ max(ceil(prob[i].a, team[j].c), 5);
				int tij = max(prob[i].i - team[j].t, 0)
						+ ceil(prob[i].a, team[j].z + team[j].c)
						+ ceil(prob[i].l, team[j].v);
				todo.push_back(ii(eij, tij));
			}
			sort(todo.begin(), todo.end());

			int ac = 0, penalty = 0, time = 0;
			for (int i = 0; i < sz(todo); i++) {
				time += todo[i].second;
				if (time > l) {
					break;
				} else {
					++ac;
					penalty += time;
				}
			}
			rank.push_back(ii(-ac, penalty));
		}

		pair<int, int> score = rank[0];
		sort(rank.begin(), rank.end());
		int rank1 = lower_bound(rank.begin(), rank.end(), score)
				- rank.begin();
		if (rank1 < mx) {
			mx = rank1;
			ans = prob_set;
		}
	} while (prev_permutation(prob_set.begin(), prob_set.end()));
	for (int i = 0; i < sz(ans); i++) {
		if (ans[i])
			printf("%d ", i + 1);
	}
	return 0;
}

