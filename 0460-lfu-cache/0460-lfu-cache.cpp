class LFUCache {
public:

int cap;
int size;

unordered_map<int, list<vector<int>>::iterator> mpp; // key -> address
map<int,list<vector<int>>> freq; // {key, value,counter}


    LFUCache(int capacity) {
        
        cap = capacity;
        size = 0;
    }

    void makemostfreqused(int key)
    {
        auto &vec = *(mpp[key]); // &vec isliye le rhe h kyuki vrna iski copy ban jaegi
        //or hum chahte h ki original me change sreflect of map ke

        int val = vec[1];
        int f = vec[2];

        freq[f].erase(mpp[key]); // humne apni dll ko address dediya ki isko uda de chal
        if(freq[f].empty())
        {
            freq.erase(f);
            // hume delete krna h agar vo empty hojati h
        }
        f++;
        freq[f].push_front({key,val,f});
        mpp[key] = freq[f].begin();

    }
    
    int get(int key) {

        if(mpp.find(key) == mpp.end())
        {
            return -1;
        }

        // auto address = mpp[key]  --> ye to address hna, ispe jab asterisk lgega tab uss node ki 
        // value milegi

        auto vec = (*(mpp[key])); // hume vo pura vector hi milgya jisme humari node stored h
        int value = vec[1]; // kyuki hum aise store krre h [key, value, counter]

        // now we have to make sure isko hum most frequently used bna dein
        makemostfreqused(key);

        return value;    
    }
    
    void put(int key, int value) {

        if(cap == 0) return;

        if(mpp.find(key) != mpp.end())
        {
            auto &vec = *(mpp[key]);
            vec[1]= value;
            makemostfreqused(key);
        }
        else if(size < cap)
        {
            size++;
            // fresh banda h
            freq[1].push_front(vector<int>({key,value,1}));
            mpp[key] = freq[1].begin();
        }
        else // jagah hi nai h humare pass, to delete krna pdega ab
        {
            // time to remove lfu or lru when there is a tie
            auto &list = freq.begin()->second; // ye vo dll hoga jisme hume remove krna h
            int keytodelete = list.back()[0];
            list.pop_back();

            if(list.empty())
            {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int>({key,value,1}));

            mpp.erase(keytodelete);
            mpp[key] = freq[1].begin();


        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */