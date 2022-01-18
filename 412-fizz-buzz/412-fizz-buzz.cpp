class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        map<int, string> m({{3, "Fizz"}, 
                            {5, "Buzz"}});
        
        for(int i = 1; i <= n; i++) {
            string str;
            for(auto n : m) {
                if(i % n.first == 0)
                    str += n.second;
            }
            
            if(str == "")
                ans.push_back(to_string(i));
            else
                ans.push_back(str);
        }
        
        return ans;
    }
};