class Solution {
public:
    string simplifyPath(string path) {
        string newPath;
        if (path.empty())
        	return path;
        
        vector<char> buffer;
        for (string::iterator iter = path.begin(); iter != path.end(); iter++) {
        	if (*iter == '.') {
        		if (iter + 1 != path.end() && *(iter+1) == '.') {
        			iter++;
        			if (!buffer.empty())
        				buffer.pop_back();
        			while (!buffer.empty() && buffer.back() != '/')
        				buffer.pop_back();
        		} else if (iter + 1 != path.end() && *(iter+1) != '/') {
        			buffer.push_back(*iter);
        		}
        	} else if (*iter == '/') {
        		if (buffer.empty() || buffer.back() != '/')
        			buffer.push_back(*iter);
        	} else
        		buffer.push_back(*iter);
        }

        if (buffer.size() <= 1)
        	return "/";
        if (buffer.back() == '/')
        	buffer.pop_back();
        for (auto iter = buffer.begin(); iter != buffer.end(); iter++) {
        	newPath += *iter;
        }
        return newPath;
    }
};