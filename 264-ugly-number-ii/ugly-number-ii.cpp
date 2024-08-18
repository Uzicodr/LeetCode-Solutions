class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> cntugly;
        
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        
        cntugly.push_back(1);

        for (int i = 1; i < n; i++) {
            int i2 = cntugly[ptr2] * 2;
            int i3 = cntugly[ptr3] * 3;
            int i5 = cntugly[ptr5] * 5;

            int leastugly = min({i2, i3, i5});
            
            cntugly.push_back(leastugly);

            if (leastugly == i2) ptr2++;
            if (leastugly == i3) ptr3++;
            if (leastugly == i5) ptr5++;
        }

        return cntugly.back();
    }
};
