const int N = 2;
const ll MOD = 1e9 + 7;

#define clr(a, b) memset(a, b, sizeof a)
struct Matrix {
    ll e[N][N];
    Matrix() { clr(e, 0);}
    void E() { for(int i = 0; i < N; i++) e[i][i] = 1;}
    ll* operator [](unsigned i) { return e[i];}
    Matrix operator * (const Matrix &R) {
        Matrix ret;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                    (ret[i][j] += e[i][k] * R[k][j]) %= MOD;
        return ret;
    }
    // type1
    Matrix power(ll n) {
        Matrix ret, a = *this;
        ret.E();
        while(n) {
            if(n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        return ret;
    }
};

// type2
Matrix power(Matrix a, ll n) {
    Matrix ret; ret.E();
    while(n) {
        if(n&1) ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}

int main() {
    Matrix A;
    init(A);
    // type1
    Matrix B = A.power(n);
    // type2
    Matrix B = power(A, n);
    return 0;
}
