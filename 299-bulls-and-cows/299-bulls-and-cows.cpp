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
                if(count[secret[i]] <= 0)
                    cows--;
            }
            else {
                if(count[guess[i]] > 0)
                    cows++;
            }
            
            count[guess[i]]--;
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};