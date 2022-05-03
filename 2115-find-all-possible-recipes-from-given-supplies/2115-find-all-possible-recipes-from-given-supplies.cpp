class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> rec(recipes.begin(), recipes.end());
        unordered_set<string> sup(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for(int i = 0; i < recipes.size(); i++) {
            for(auto ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
                if(rec.find(ingredient) == rec.end())
                    indegree[ingredient] = 0;
            }
        }
        
        queue<string> q;
        for(auto in : indegree) {
            if(in.second == 0)
                q.push(in.first);
        }
        
        while(!q.empty()) {
            string ingredient = q.front(); q.pop();
            if(sup.find(ingredient) == sup.end())
                continue;
            
            for(auto food : graph[ingredient]) {
                if(--indegree[food] == 0) {
                    q.push(food);
                    sup.insert(food);
                    ans.push_back(food);
                }
            }
        }
        
        return ans;
    }
};

/*
recipes = ["bread","sandwich","burger"]
ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]]
supplies = ["yeast","flour","meat"]
    
        "yeast"d  
           
           
        "bread"d    "sandwich"d   "meat"d
              \          |          /
                \        V        /
        "flour"d  >   "burger"d  <
    
    d
    one of recipes ?
        yes : add it into answer
        
    key         val
    yeast       bread
    flour       bread
    bread       sandwich, burger
    meat        sandwich, burger
    sandwich    burger
    */