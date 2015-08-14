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

vi primes;
int num[32001];

void init() {
	num[0] = num[1] = 1;
	for (int i = 2; i * i < 32000; i++) {
		if (!num[i]) {
			for (int j = i * i; j < 32000; j += i)
				num[j] = 1;
		}
	}
	for (int i = 2; i < 32000; i++)
		if (!num[i])
			primes.push_back(i);
}

int main() {
//	freopen("in.txt","r",stdin);
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n;
		scanf("%d %d", &m, &n);
		if (m < 2)
			m = 2;
		set<int> not_prime;
		for (int i = 0; i < sz(primes); i++) {
			if(primes[i] > sqrt(n)+1)
				break;
			int s;
			if (primes[i] >= m)
				s = primes[i] * 2;
			else {
				if (m % primes[i] == 0)
					s = primes[i] * ((m / primes[i]));
				else
					s = primes[i] * ((m / primes[i]) + 1);
			}
			for (int j = s; j <= n; j += primes[i])
				not_prime.insert(j);
		}
		for(int i=m;i<=n;i++){
			if(not_prime.count(i)==0)
				printf("%d\n",i);
		}
		if(t)
			printf("\n");
	}
	return 0;
}

