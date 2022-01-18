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
        int max_depth = INT_MIN;
        int sumOfElements = 0, sumOfProducts = 0;
        queue<NestedInteger> q;
        int depth = 1;
        
        for(auto l : nestedList)
            q.push(l);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                NestedInteger nest = q.front();
                q.pop();
                if(nest.isInteger()) {
                    sumOfElements += nest.getInteger();
                    sumOfProducts += nest.getInteger() * depth;
                }
                else {
                    for(auto l : nest.getList())
                        q.push(l);
                }
            }
            
            max_depth = max(max_depth, depth);
            depth++;
        }
        
        
        return (max_depth + 1) * sumOfElements - sumOfProducts;
    }
    
};