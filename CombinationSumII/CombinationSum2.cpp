class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        bool used[100];
        map<int, vector<vector<int> > > paths;
    	vector<vector<int> > result;

	    memset(used, 0, sizeof(used));
    	used[0] = true;
	    //vector<int> used;
        //used.push_back(0);
        sort(num.begin(), num.end());
	    for (vector<int>::iterator i = num.begin(); i != num.end(); i++) {
		    for (int j = 40-*i; j >=0 ; j--) {
            //int size = used.size();
			//for (int j = size-1; j >= 0; j--) {
                if (!used[j])
			    	continue;
			    newPath(paths, j, *i);
			    used[*i+j] = true;
                //used.push_back(used[j]+*i);
		    }
	    }
	    map<int, vector<vector<int> > >::iterator iterator = paths.find(target);
	    if (iterator != paths.end()) {
	    	result = iterator->second;
	    }
	    return result;
        
    }
    
    void newPath(map<int, vector<vector<int> > > &paths, int a, int b) {
        if (a != 0) {
	    	map<int, vector<vector<int> > >::iterator i = paths.find(a);
	    	if (i != paths.end()) {
	    		vector<vector<int> > p = i->second;
	    		if (p.size() == 0) {
		    		vector<int> t;
		    		t.push_back(b);
		    		p.push_back(t);
		    	} else {
		    		for (vector<vector<int> >::iterator j = p.begin(); j != p.end(); j++) {
		    			(*j).push_back(b);
		    		}
		    	}
			    map<int, vector<vector<int> > >::iterator j = paths.find(a+b);
			    if (j == paths.end()) {
			    	paths.insert(pair<int, vector<vector<int> > >(a+b, p));
			    } else {
			    	for (vector<vector<int> >::iterator k = p.begin(); k != p.end(); k++) {
			    		if (find(paths[a+b].begin(), paths[a+b].end(), *k) == paths[a+b].end())
                            paths[a+b].push_back(*k);			
			    	}
			    }
		    }
	    } else {
            vector<int> x;
	    	x.push_back(b);
	    	if (find(paths[b].begin(), paths[b].end(), x) == paths[b].end())
                paths[b].push_back(x);
	    }
    }
};