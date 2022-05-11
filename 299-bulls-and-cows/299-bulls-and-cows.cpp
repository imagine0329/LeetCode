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

/*
secret = "1807", guess = "7810"
bulls = 1, cows = 3

1: 1
2: 1
8: 0
0: -1
7: 0
    
    i        j
"18207"  "78001"

1 != 7 && 7 exists -> cows++, m[7]--
8 == 8 -> bulls++, m[8]--
2 != 0 
    if(m[0] > 0)
        cows++, m[0]--
        
0 == 0 -> bulls++
    if(m[0]-- <= 0)
        cows--
    */