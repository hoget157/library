//line fitting to ax+b
pair<double,double> leastSquare(vector<pair<double,double>> data){
	double sxy = 0,sx = 0,sy = 0,sx2 = 0;
	for(auto &p : data){
		sxy += p.first * p.second;
		sx += p.first;
		sy += p.second;
		sx2 += p.first * p.first;
	}
	int n = data.size();
	double a = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
	double b = (sx2 * sy - sx * sxy) / (n * sx2 - sx * sx);
	return make_pair(a,b);
}