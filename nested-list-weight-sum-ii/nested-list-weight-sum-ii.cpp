/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 1;
        int maxDepth = dfs(nestedList);
        int sum = 0;
        queue<NestedInteger> q;
        
        for(auto n : nestedList)
            q.push(n);
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                NestedInteger temp = q.front();
                q.pop();
                
                if(temp.isInteger())
                    sum += temp.getInteger() * (maxDepth - depth + 1);
                else
                {
                    for(auto n : temp.getList())
                        q.push(n);
                }
            }
            
            depth++;
        }
        
        return sum;
    }
    
    int dfs(vector<NestedInteger>& nestedList)
    {
        int maxDepth = 1;
        for(auto n : nestedList)
        {
            if(!n.isInteger())
                maxDepth = max(maxDepth, 1 + dfs(n.getList()));
        }
        
        return maxDepth;
    }
};