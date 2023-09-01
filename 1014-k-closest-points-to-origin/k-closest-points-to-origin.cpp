class Solution {
public:
    
    typedef pair<int, pair<int, int> > pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pi> maxH;
        vector<vector<int>> ans;

        for(int i=0; i<points.size(); i++){

            maxH.push({pow(points[i][0], 2) + 
                            pow(points[i][1], 2), 
                            {points[i][0], points[i][1]}});

            if(maxH.size() > k)
                maxH.pop();
        }
        
        while(!maxH.empty()){
            ans.push_back({maxH.top().second.first, maxH.top().second.second});
            maxH.pop();
        }
        return ans;
        
    }
};