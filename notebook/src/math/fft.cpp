using cpx = complex<double>;
const double PI = acos(-1);

void fillPrimRoots(cpx* vec, lli n, bool conjugate)
{
    double s = conjugate ? -1 : 1;
    forn(i, n / 2)
        vec[i] = polar(1., s * 2 * PI * i / n);
}

struct FFT
{
    lli n;
    vector<cpx> rt, rtc;
    vi rev;

    FFT(lli base) : n(1 << base), rt(n, 0), rtc(n), rev(n)
    {
        forn(i, n)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
        fillPrimRoots(rt.data() + n / 2, n, false);
        fillPrimRoots(rtc.data() + n / 2, n, true);
        ford(i, 0, n / 2)
        {
            rt[i] = rt[2 * i];
            rtc[i] = rtc[2 * i];
        }
    }

    void fft(cpx* a, bool inv = false) const
    {
        const cpx* roots = inv ? rtc.data() : rt.data();
        forn(i, n)
            if(i < rev[i])
                swap(a[i], a[rev[i]]);
        for(lli k = 1; k < n; k <<= 1)
            for(lli i = 0; i < n; i += 2 * k)
                forn(j, k)
                {
                    cpx z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
        if(inv)
        {
            cpx invn = cpx(1) / cpx(n);
            forn(i, n)
                a[i] *= invn;
        }
    }
};

vi multFFT(const FFT& fft, const vi& a, const vi& b)
{
    lli n = fft.n;
    assert(a.size() == n && b.size() == n);
    vector<cpx> c(n);
    forn(i, n)
        c[i] = cpx(a[i], b[i]);
    fft.fft(c.data());
    vector<cpx> f = c;
    forn(i, n)
    {
        lli j = (n - i) & (n - 1);
        c[i] = (f[j] * f[j] - conj(f[i] * f[i])) * cpx(0, -.25 / n);
    }
    fft.fft(c.data());
    vi res(n);
    forn(i, n)
        res[i] = (lli) round(c[i].real());
    return res;
}
