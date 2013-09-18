class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return path;
        int i = 0;
        vector<char> buffer;
        while (i < path.length()) {
        	if (path[i] == '/') {
        		if (buffer.empty() || buffer.back() != '/')
        			buffer.push_back(path[i]);
        	} else if (path[i] == '.') {
        		if (i + 1 < path.length() && path[i+1] == '.') {
        			i++;
        			if (!buffer.empty())
        				buffer.pop_back();
        			while (!buffer.empty() && buffer.back() != '/')
        				buffer.pop_back();
        		} else if (i + 1 < path.length() && path[i+1] != '/')
        			buffer.push_back(path[i]);
        	} else
        		buffer.push_back(path[i]);
        	i++;
        }
        if (buffer.size() < 2)
        	return "/";
        if (buffer.back() == '/')
        	buffer.pop_back();
        string res;
        for (vector<char>::iterator iter = buffer.begin(); iter != buffer.end(); iter++)
        	res.push_back(*iter);
        return res;
    }
};