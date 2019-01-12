typedef long long ll;

ll power_mod(ll a, ll b, ll MOD) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

//  Fermat's little theory
ll inv(ll a, ll p) { // p is a prime
    return power_mod(a, p - 2, MOD);
}
