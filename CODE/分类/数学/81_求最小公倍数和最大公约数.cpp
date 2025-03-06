long int gcd(long int a,long int b) {
    while (b!=0) {
        long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}






long int lcm(long int a,long int b){
    return (a / gcd(a, b) * b);
}

/*
a = m*g
b = n*g
g为最大公约数
最小公倍数 = m*n*g
*/