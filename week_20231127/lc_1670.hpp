class FrontMiddleBackQueue {
public:
    vector<int> d;

    FrontMiddleBackQueue() {
        d = vector<int>();
    }
    
    void pushFront(int val) {
        d.insert(d.begin(), val);
    }
    
    void pushMiddle(int val) {
        d.insert(d.begin() + d.size()/2, val);
    }
    
    void pushBack(int val) {
        d.push_back(val);
    }
    
    int popFront() {
        if(d.size() == 0){
            return -1;
        }
        int tmp = d[0];
        d.erase(d.begin());
        return tmp;
    }
    
    int popMiddle() {
        if(d.size() == 0){
            return -1;
        }
        int tmp = d[ceil(d.size()/2.0)-1];
        d.erase(d.begin()+ceil(d.size()/2.0)-1);
        return tmp;
    }
    
    int popBack() {
        if(d.size() == 0){
            return -1;
        }
        int tmp = d[d.size()-1];
        d.pop_back();
        return tmp;
    }
};
