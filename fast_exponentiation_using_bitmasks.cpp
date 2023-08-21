//1 ≤ x, n, M ≤ 109...Time complexity : O(logN)
long long int PowMod(long long int x,long long int n,long long int M) {
	// Code here
	long long int ans = 1;
		    
	while(n > 0) {
		int last_bit = (n&1);

		if(last_bit) {
		    ans = (ans * x)%M;
		}
		x = (x * x)%M;
		n = n >> 1;
	}
		    
	return ans;
}