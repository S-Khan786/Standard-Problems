//The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n
int ans[1000005] = {0};

//Sieve of Eratosthenes
void solve1() {

    ans[0] = ans[1] = 0;
    ans[2] = 1;

    //First mark all odd number as prime
    for(int i=3; i<=1000000; i+=2) {
        ans[i] = 1;
    }

    for(int i=3; i<=1000000; i++) {

		//If value of that cell is 1 it means that it is prime
        if(ans[i] == 1) {

			//Mark all the multiples of that number is not Prime
            for(int j=i*i; j<=1000000; j = j+i) {
                ans[j] = 0;
            }
        }
    }
}
