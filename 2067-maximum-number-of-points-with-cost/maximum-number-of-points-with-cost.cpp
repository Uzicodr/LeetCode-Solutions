class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> prev(points[0].size(),0);

        for(int i=0;i<points[0].size();i++)
        prev[i]=points[0][i];

        for(int i=1;i<points.size();i++)
        {
            vector<long long> adjleft(points[0].size(),0);
            vector<long long> adjright(points[0].size(),0);
            vector<long long> curr(points[0].size(),0);

            adjleft.front()=prev.front();
            adjright.back()=prev.back();

            for(int j=1;j<adjleft.size();j++)
            adjleft[j]=max(prev[j],adjleft[j-1]-1);

            for(int j=points[0].size()-2;j>=0;j--)
            adjright[j]=max(prev[j],adjright[j+1]-1);

            for(int j=0;j<points[0].size();j++)
            curr[j]=points[i][j]+max(adjleft[j],adjright[j]);

            prev=curr;
        }
        return *max_element(prev.begin(),prev.end());
    }
};