template<class Tdomain,class Tcodomain,class Tfunction>
Tdomain goldenSectionSearch(Tdomain low,Tdomain up,Tfunction func,int loop = 100){
	const double prop = 0.3819660112501053195;
	Tdomain mid1 = (up - low) * prop + low,mid2 = up - (up - low) * prop;
	Tcodomain fmid1 = func(mid1),fmid2 = func(mid2);
	for(int i = 0;i < loop;i++){
		if(fmid1 < fmid2){
			up = mid2;
			mid2 = mid1; fmid2 = fmid1;
			mid1 = (up - low) * prop + low;
			fmid1 = func(mid1);
		}else{
			low = mid1;
			mid1 = mid2; fmid1 = fmid2;
			mid2 = up - (up - low) * prop;
			fmid2 = func(mid2);
		}
	}
	return (low + up) / 2.0;
}
//!!!!!!unverified!!!!!!