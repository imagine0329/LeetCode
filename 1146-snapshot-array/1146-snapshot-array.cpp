class SnapshotArray {
private:
    unordered_map<int, int> arr;
    unordered_map<int, unordered_map<int, int>> snapshots;
    int id = 0;

public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        snapshots[id] = arr;
        
        return id++;
    }
    
    int get(int index, int snap_id) {
        return snapshots[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
/*
["SnapshotArray","set","snap","set","get"]
[   [3],         [0,5],  [],  [0,6],[0,0]]


0: 5(0), 6
1
2
    
key     val
index   val
0       5

key     val
index   [key,    val]
        snap_id, val
0       [0,     5]
*/