class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        if (start.compare(end) == 0 || dict.empty())
            return res;
        unordered_map<string, bool> used;
        for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            used[*iter] = false;
        vector<string> prev;
        prev.push_back(start);
        map<string, vector<string> > pre_words;
        used[start] = true;
        bool flag = false;
        while (!prev.empty()) {
        	vector<string> curr;
        	for (vector<string>::iterator word = prev.begin(); word != prev.end(); word++) {
        		string new_word = *word;
        		for (int i = 0; i < word->length(); i++) {
        			for (int k = 'a'; k <= 'z'; k++) {
        				if ((*word)[i] == k)
        					continue;
        				char temp = new_word[i];
        				new_word[i] = k;
        				if (end.compare(new_word) == 0) {
        					flag = true;
        					pre_words[new_word].push_back(*word);
        				} else {
        					if (dict.count(new_word) > 0 && !used[new_word]) {
        						if (find(curr.begin(), curr.end(), new_word) == curr.end())
                                    curr.push_back(new_word);
        						pre_words[new_word].push_back(*word);
        					}
        				}
        				new_word[i] = temp;
        			}
        		}
        	}
            if (flag)
            	break;
            if (curr.empty() && !flag)
                return res;
            for (vector<string>::iterator iter = curr.begin(); iter != curr.end(); iter++)
                used[*iter] = true;
        	prev = curr;
        }
        vector<string> path;
        buildPath(end, pre_words, path, res);
        return res;
    }

    void buildPath(string word, map<string, vector<string> > &pre_words, vector<string> &path, vector<vector<string> > &res) {
    	if (pre_words[word].empty()) {
    		path.push_back(word);
    		vector<string> curr_path = path;
    		reverse(curr_path.begin(), curr_path.end());
    		res.push_back(curr_path);
    		path.pop_back();
    		return;
    	}

    	const vector<string> &preWords = pre_words[word];
    	path.push_back(word);
    	for (vector<string>::const_iterator iter = preWords.begin(); iter != preWords.end(); iter++) {
    		buildPath(*iter, pre_words, path, res);
    	}
    	path.pop_back();
    }
};