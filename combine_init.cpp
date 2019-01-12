typedef long long ll;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

ll F[N], invF[N];
ll inv[N];

void init_inv() {
    // type1: complexity(O(nlogn))
    for(int i = 1; i < N; i++)
        inv[i] = power_mod(i, MOD - 2);

    // type2: complexity(O(n))
    inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
}

void combine_init() {
    F[0] = invF[0] = 1;
    for(int i = 1; i < N; i++)
        F[i] = F[i - 1] * i % MOD;

    // type1: complexity(O(nlogn))
    for(int i = 1; i < N; i++)
        invF[i] = power_mod(F[i], MOD - 2);

    // type2: complexity(O(n))
    invF[N - 1] = power_mod(invF[N - 1], MOD - 2);
    for(int i = N - 2; i; i--)
        invF[i] = invF[i + 1] * (i + 1) % MOD;
}

ll C(int n, int m) {
    if(m > n || m < 0) return 0;
    return F[n] * invF[m] % MOD * invF[n - m] % MOD;
}
