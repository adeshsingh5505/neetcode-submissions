#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({position[i], speed[i]});
        }

        sort(p.rbegin(), p.rend());

        vector<double> time;
        for (int i = 0; i < n; i++) {
            double t = (double)(target - p[i].first) / p[i].second;
            time.push_back(t);
        }
        for (double t : time) cout << t << " ";
        cout << endl;

        int fleets = 0;
        double lastTime = 0;
        for (double t : time) {
            if (t > lastTime) {
                fleets++;
                lastTime = t;
            }
        }

        return fleets;
    }
};
