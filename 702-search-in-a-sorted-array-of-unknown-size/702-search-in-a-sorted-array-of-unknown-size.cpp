/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 1;
        
        while(reader.get(right) < target) {
            left = right;
            right <<= 1;
        }
        
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(reader.get(mid) == target)
                return mid;
            
            if(reader.get(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
};