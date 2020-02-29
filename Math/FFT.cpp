namespace FFT{
	using Float = double;
	using Complex = complex<Float>;
	const Float PI = 3.141592653589793;

	void fft(vector<Complex> &a,int n,int inv){
		for(int i = 0,j = 1;j < n - 1;j++){
			for(int k = n >> 1;k > (i ^= k);k >>= 1);
			if(i < j) swap(a[i],a[j]);
		}
		for(int i = 1;i < n;i <<= 1){
			int irev = 0;
			for(int j = 0;j < n;j += i * 2){
				Float theta = PI * 2 / n * irev * inv;
				Complex w(cos(theta),sin(theta));
				for(int k = n >> 2;k > (irev ^= k);k >>= 1);
				for(int k = j;k < i + j;k++){
					Complex x = a[k] - a[k + i];
					a[k] += a[k + i];
					a[k + i] = w * x;
				}
			}
		}
		if(inv == -1) for(int i = 0;i < n;i++) a[i] /= n;
	}

	template<class T>
	vector<Float> conv(const vector<T> &a,const vector<T> &b){
		int n = 1,deg = a.size() + b.size() - 1;
		while(n < deg) n <<= 1;
		vector<Complex> p(n),c(n);
		for(int i = 0;i < a.size();i++) p[i].real(a[i]);
		for(int i = 0;i < b.size();i++) p[i].imag(b[i]);
		fft(p,n,1);
		for(int i = 0;i < n;i++){
			c[i] = (p[i] - conj(p[(n - i) % n])) * (p[i] + conj(p[(n - i) % n])) * Complex(0,-0.25);
		}
		fft(c,n,-1);
		vector<Float> ans(deg);
		for(int i = 0;i < deg;i++) ans[i] = round(c[i].real());
		return ans;
	}
};
//verified: https://atcoder.jp/contests/atc001/submissions/10404892