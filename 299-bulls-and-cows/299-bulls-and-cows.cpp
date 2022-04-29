class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> count;
        int bulls = 0, cows = 0;
        
        for(int i = 0; i < secret.length(); i++) {
            char s = secret[i], g = guess[i];
            if(s == g)
                bulls++;
            else {
                if(count[s] < 0)
                    cows++;
                if(count[g] > 0)
                    cows++;
                
                count[s]++;
                count[g]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};