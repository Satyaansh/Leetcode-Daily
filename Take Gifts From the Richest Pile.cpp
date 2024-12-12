/*
Take Gifts From the Richest Pile
Link : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
Logic : Use max heap for k iterations. Pretty straightforward.
*/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long ans = 0;
        priority_queue<int> q;
        for(int i = 0; i < n; i++) {
            ans += gifts[i];
            q.push(gifts[i]);
        }
        while(k--) {
            auto p = q.top();
            q.pop();
            int r = floor(sqrt(p));
            ans -= (p - r);
            q.push(r);
        }
        return ans;
    }
};