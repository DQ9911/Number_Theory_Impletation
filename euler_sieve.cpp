const int N = 1e6 + 7;

int p[N / 8], pn = 0;
bool np[N]; // if i is not prime, np[i] = 1

int mu[N], phi[N];

void euler_sieve() {
    phi[1] = 1;
    mu[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!np[i]) {
            p[pn++] = i;
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for(int j = 0; j < pn && i * p[j] < N; j++) {
            np[i * p[j]] = 1;
            if(i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                // mu[i * p[j]] = 0;
                break;
            } else phi[i * p[j]] = phi[i] * (p[j] - 1), mu[i * p[j]] = -mu[i];
        }
    }
}
