int factorial(int val1){
    int n;
    int sum;
    for(n = val1; n > 1; n--){
        sum = (n - 1) * n;
    }
    return sum;
}