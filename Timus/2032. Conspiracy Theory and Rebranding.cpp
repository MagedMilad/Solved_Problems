//============================================================================
// Name        : Practice.cpp
// author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

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

const ll oo = (ll) 1e9 + 1;
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
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}


int main() {
//	freopen("in.txt","r",stdin);
	ll len[3];
	cin >> len[0] >> len[1] >> len[2];
	sort(len, len + 3);
	ll mx = (ll)(sqrt(2*len[2])+eps);
	vector<pointINT> p1, p2;
	for (ll i = 1; i <= mx; i += 2) {
		for (ll j = i + 2; j <= mx; j += 2) {
			if (gcd(i, j) > 1)
				continue;
			ll a = i * j;
			ll b = (j * j - i * i) / 2;
			ll c = (j * j + i * i) / 2;
			if (len[0] % c == 0) {
				p1.push_back(pointINT(a * len[0] / c, b * len[0] / c));
				p1.push_back(pointINT(a * len[0] / c, -b * len[0] / c));
				p1.push_back(pointINT(-a * len[0] / c, b * len[0] / c));
				p1.push_back(pointINT(-a * len[0] / c, -b * len[0] / c));
				p1.push_back(pointINT(b * len[0] / c, a * len[0] / c));
				p1.push_back(pointINT(b * len[0] / c, -a * len[0] / c));
				p1.push_back(pointINT(-b * len[0] / c, a * len[0] / c));
				p1.push_back(pointINT(-b * len[0] / c, -a * len[0] / c));
			}
			if (len[1] % c == 0) {
				p2.push_back(pointINT(a * len[1] / c, b * len[1] / c));
				p2.push_back(pointINT(a * len[1] / c, -b * len[1] / c));
				p2.push_back(pointINT(-a * len[1] / c, b * len[1] / c));
				p2.push_back(pointINT(-a * len[1] / c, -b * len[1] / c));
				p2.push_back(pointINT(b * len[1] / c, a * len[1] / c));
				p2.push_back(pointINT(b * len[1] / c, -a * len[1] / c));
				p2.push_back(pointINT(-b * len[1] / c, a * len[1] / c));
				p2.push_back(pointINT(-b * len[1] / c, -a * len[1] / c));
			}
		}
	}
	p1.push_back(pointINT(0, len[0]));
	p1.push_back(pointINT(0, -len[0]));
	p1.push_back(pointINT(len[0], 0));
	p1.push_back(pointINT(-len[0], 0));
	p2.push_back(pointINT(0, len[1]));
	p2.push_back(pointINT(0, -len[1]));
	p2.push_back(pointINT(len[1], 0));
	p2.push_back(pointINT(-len[1], 0));
	for(ll i=0;i<sz(p1);i++){
		for(ll j=0;j<sz(p2);j++){
//			ll d = distsqr(p1[i],p2[j]);
			if((p1[i].real()-p2[j].real())*(p1[i].real()-p2[j].real())+(p1[i].imag()-p2[j].imag())*(p1[i].imag()-p2[j].imag()) == len[2]*len[2]){
				printf("0 0\n%I64d %I64d\n%I64d %I64d\n",p1[i].real(),p1[i].imag(),p2[j].real(),p2[j].imag());
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}

