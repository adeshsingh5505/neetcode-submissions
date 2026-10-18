class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five > 0) {
                    five -= 1;
                } else {
                    return 0;
                }
                class Solution {
                public:
                    bool lemonadeChange(vector<int>& bills) {
                        int f = 0, t = 0, tt = 0;
                        for (auto& i : bills) {
                            if (i == 5) {
                                f++;
                                continue;
                            }
                            if (i == 10) {
                                if (f == 0)
                                    return 0;
                                t++;
                                f--;
                            }
                            if (i == 20) {
                                if (f > 0 && t > 0) {
                                    f--;
                                    t--;
                                    tt++;
                                    continue;
                                } else if (f >= 3) {
                                    f -= 3;
                                    tt++;
                                    continue;
                                } else {
                                    return 0;
                                }
                            }
                        }
                        return 1;
                    }
                };
                ten++;
            } else if (bills[i] == 20) {
                if (five && ten) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five = five - 3;
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
};