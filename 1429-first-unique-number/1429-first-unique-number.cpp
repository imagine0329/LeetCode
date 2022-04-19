//  [key - value]
//  num - count
//  num - iterator

//  unique num list
//  2   3   5
//  

class FirstUnique {
private:
    unordered_map<int, int> count;
    list<int> unique;
    unordered_map<int, list<int>::iterator> it;
    
public:
    FirstUnique(vector<int>& nums) {
        for(auto n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        if(unique.size() == 0)
            return -1;
        return unique.back();
    }
    
    void add(int val) {
        if(++count[val] > 1) {
            if(it.find(val) != it.end()) {
                unique.erase(it[val]);
                it.erase(val);
            }
        }
        else {
            unique.push_front(val);
            it[val] = unique.begin();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */