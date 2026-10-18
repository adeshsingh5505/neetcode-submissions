class Solution {
//put pointer at highest and lowest if high+low<limit put both else put high
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int h=n-1,l=0;
        int cnt=0;
        while(l<=h){
            if(people[h]+people[l]<=limit){
                l++;h--;
            }
            else{
                h--;
            }
            cnt++;
        }
        return cnt;
    }
};