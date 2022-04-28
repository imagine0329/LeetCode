class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> count;
        int bulls = 0, cows = 0;
        
        for(auto c : secret)
            count[c]++;
        
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                if(--count[secret[i]] == 0)
                    count.erase(secret[i]);
            }
        }
        
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] != guess[i]) {
                if(count.find(guess[i]) != count.end()) {
                    if(--count[guess[i]] == 0)
                        count.erase(guess[i]);
                    cows++;
                }
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};