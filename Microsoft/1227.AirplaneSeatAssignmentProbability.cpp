// 1227. Airplane Seat Assignment Probability
// Link: https://leetcode.com/problems/airplane-seat-assignment-probability/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
         return (n == 1 ? (double)1 : (double)1/2);
    }
};
