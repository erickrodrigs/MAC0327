#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <const int MOD>
struct mint
{
    ll x;
    mint() : x(0) {}
    mint(ll _x) : x(_x % MOD < 0 ? _x % MOD + MOD : _x % MOD) {}
    void operator+=(mint rhs)
    {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
    }
    void operator-=(mint rhs)
    {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
    }
    void operator*=(mint rhs)
    {
        x *= rhs.x;
        x %= MOD;
    }
    void operator/=(mint rhs) { *this *= rhs.inv(); }
    mint operator+(mint rhs)
    {
        mint res = *this;
        res += rhs;
        return res;
    }
    mint operator-(mint rhs)
    {
        mint res = *this;
        res -= rhs;
        return res;
    }
    mint operator*(mint rhs)
    {
        mint res = *this;
        res *= rhs;
        return res;
    }
    mint operator/(mint rhs)
    {
        mint res = *this;
        res /= rhs;
        return res;
    }
    mint inv() { return this->pow(MOD - 2); }
    mint pow(ll e)
    {
        mint res(1);
        for (mint p = *this; e > 0; e /= 2, p *= p)
            if (e % 2)
                res *= p;
        return res;
    }
};

using Z = mint<1000000007>;

vector<Z> fact = {1, 1};

Z C(int a, int b)
{
    for (int i = fact.size(); i <= max(a, b); i++)
    {
        fact.push_back(i * fact[i - 1]);
    }

    return fact[a] / (fact[b] * fact[a - b])
}

int main()
{
    int n;

    cin >> n;

    while (n > 0)
    {
        int a, b;

        cin >> a >> b;

        cout << C(a, b) << endl;

        n -= 1;
    }

    return 0;
}
