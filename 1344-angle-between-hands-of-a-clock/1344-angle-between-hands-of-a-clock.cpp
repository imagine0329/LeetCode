class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h_hand, m_hand;
        
        h_hand = (hour * 30) + (minutes * 0.5);
        m_hand = minutes * 6;
        
        double degree = abs(h_hand - m_hand);
        return degree > 180 ? 360 - degree : degree;
    }
};