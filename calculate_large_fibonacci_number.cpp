//Calculate upto 10^18th fibonacci number from below code
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7; // modulo
map<ll, ll> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

int main(){
	ll n;
	F[0]=F[1]=1;
	while (cin >> n)
	cout << (n==0 ? 0 : f(n-1)) << endl;

    return 0;
}
//The complexity of above code is O(logn * log(logn))
