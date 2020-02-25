template<int char_size>
struct Trie{
	struct Node{
		int nxt[char_size];

		int childs;
		bool isExist;

		Node() : childs(0),isExist(false){
			fill(nxt,nxt + char_size,-1);
		}
	};

	inline int ctoi_default(char c) const{
		return c - 'a';
	}

	using F = function<int(char)>;
	F ctoi;
	vector<Node> nodes;

	Trie(F ctoi = ctoi_default) : ctoi(ctoi){
		nodes.emplace_back();
	}

	inline int &next(int pos,int c){
		return nodes[pos].next[c];
	}

	inline int &next(int pos,char c){
		return next(pos,ctoi(c));
	}

	void add(const string &s){
		int pos = 0;
		for(int i = 0;i < s.length();i++){
			const int c = ctoi(s[i]);
			if(next(pos,c) == -1){
				next(pos,c) = nodes.size();
				nodes.emplace_back();
			}
			pos = next(pos,c);
			nodes[pos].childs++;
		}
		nodes[pos].isExist = true;
	}

	int find(const string &s) const{
		int pos = 0;
		for(int i = 0;i < s.length();i++){
			const int c = ctoi(s[i]);
			if(next(pos,c) == -1) return -1;
			pos = next(pos,c);
		}
		return pos;
	}
};
//!!!!!!unverified!!!!!!
//https://atcoder.jp/contests/tenka1-2016-final-open/submissions/9134674