class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<double,double>> pt;

        for(int i = 0 ; i < n ; i++){
            double time = (double)(target - position[i]) / speed[i];
            pt.push_back({position[i],time});
        }

        // descending order
        sort(pt.begin(),pt.end(),[](auto& a,auto& b){
                return a.first>b.first;
        });

        double maxfleet = 0;
        int fleet = 0;

        for(auto it:pt){
            double t = it.second;

            if(t > maxfleet){
                maxfleet = t;
                fleet++;;
            }
        }

        return fleet;
    }
};
