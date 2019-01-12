typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) { x = 1, y = 0; return a;}
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll inv(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (x + m) % m;
}
