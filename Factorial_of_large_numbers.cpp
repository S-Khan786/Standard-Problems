void multiply(vector<int>& arr, int &digit, int no) {
    int carry = 0;
    
    for(int i=0; i<digit; i++) {
        int product = arr[i]*no + carry;
        arr[i] = product%10;
        carry = product/10;
    }
    
    while(carry) {
        arr[digit] = carry%10;
        carry = carry/10;
        digit++;
    }
}

vector<int> factorial(int N){
    // code here
    vector<int> arr(10000, 0);
    
    arr[0] = 1;
    int digit = 1;
    
    for(int i=2; i<=N; i++) {
        multiply(arr, digit, i);
    }
    
    vector<int> ans;
    for(int i=(digit - 1); i>=0; i--) {
        ans.push_back(arr[i]);
    }
    
    return ans;
}
