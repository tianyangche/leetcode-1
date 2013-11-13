class LRUCache{
public:
    LRUCache(int capacity) {
        cache_ = Table();
        data_  = list<int>();
        capacity_ = capacity;
    }

    int get(int key) {
        auto pos = cache_.find(key);
        if (pos == cache_.end())
        	return -1;
        make_front(pos, key);
        return pos->second.second;
    }

    void set(int key, int value) {
        auto pos = cache_.find(key);
        if (pos != cache_.end()) {
        	pos->second.second = value;
        	make_front(pos, key);
        } else {
        	if (data_.size() >= capacity_) {
        		cache_.erase(data_.back());
        		data_.pop_back();
        	}
        	data_.emplace_front(key);
        	cache_[key] = {data_.begin(), value};
        }
    }

private:
	typedef unordered_map<int, pair<list<int>::iterator, int> > Table;
	Table cache_;
	list<int> data_;
	int capacity_;

	void make_front(Table::iterator iter, int key) {
		data_.erase(iter->second.first);
		data_.emplace_front(key);
		iter->second.first = data_.begin();
	}
};