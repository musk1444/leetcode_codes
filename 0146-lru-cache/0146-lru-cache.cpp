class LRUCache {
public:

list<int> dll;
// and we keep a map[key] = {address of ll,value in ll}
map<int, pair<list<int>::iterator , int>> mpp;
int n;

    LRUCache(int capacity) {
        n = capacity;
        
    }
    void mostrecentlyused(int key)
    {
        dll.erase(mpp[key].first); // this will eras ethe ll at the specified address
        dll.push_front(key);

        mpp[key].first = dll.begin(); // mark its new address as the first element
    }
    int get(int key) {

        if(mpp.find(key) == mpp.end())
        {
            return -1;
        }

        // make the key as most recently used
        mostrecentlyused(key);
        return mpp[key].second;
        
    }
    
    void put(int key, int value) {

        if(mpp.find(key) != mpp.end())
        {
            mpp[key].second = value;
            mostrecentlyused(key);
        }
        else
        {
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            n--;
        }

        // at any point the capacity goes beyond 0, means we nee dto erase
        if(n < 0)
        {
            int key_tobe_del = dll.back();
            mpp.erase(key_tobe_del);
            dll.pop_back();

            // increase the capacity again
            n++;
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */