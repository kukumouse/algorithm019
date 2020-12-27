class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0,pow = 31;
        while (n > 0){
            res += (n & 1) << pow;
            n = n >> 1;
            pow--;
        }
        return res;

        
    }
};