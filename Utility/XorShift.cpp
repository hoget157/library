uint32_t xor128(){
	static uint32_t x = 123456789,y = 362436069,z = 521288629,w = 88675123;
	uint32_t t;
	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}