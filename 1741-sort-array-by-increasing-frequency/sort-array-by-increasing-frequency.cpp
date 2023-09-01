class Solution {
public:
    
    typedef pair<int, int> pi;

    vector<int> frequencySort(vector<int>& nums) {
        
        priority_queue<pi, vector<pi>, greater<pi>> minH;
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for(auto &i:m){
            minH.push({i.second, -1*i.first});
        }

        while(!minH.empty()){
            for(int i=0; i<minH.top().first; i++){
                ans.push_back(-1*minH.top().second);
            }
            minH.pop();
        }
        return ans;
    }
};