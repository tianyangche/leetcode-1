bool findChar(unordered_map<char, int> &freq, unordered_map<char, int> &prev, int dist, int i, char &ch) {

    int max_freq = 0;
    for (auto iter = freq.begin(); iter != freq.end(); iter++) {
        if (iter->second > max_freq && (prev.count(iter->first) <= 0 || prev[iter->first] + dist <= i)) {
            max_freq = iter->second;
            ch = iter->first;
        }
    }
    return max_freq == 0 ? false : true;
}

string reorderDistance(string str, int dist) {

    string res;

    if (str.empty())
        return res;

    unordered_map<char, int> freq;
    unordered_map<char, int> prev;

    for (char &ch : str) {
        freq[ch]++;
    }

    for (string::size_type i = 0; i < str.length(); i++) {
        char ch = ' ';
        if (!findChar(freq, prev, dist, i, ch))
            return "ERROR!";
        freq[ch]--;
        prev[ch] = i;
        res.push_back(ch);
    }

    return res;
}