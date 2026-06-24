class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        for(char task : tasks){
            freq[task]++;
        }

        priority_queue<int> pq;

        for(auto &[task,count] : freq){
            pq.push(count);
        }

        int time = 0 ;

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1 ; i <= n + 1 ; i++){
                if(!pq.empty()){

                int first = pq.top();
                pq.pop();

                first--;

                if(first>0){
                temp.push_back(first);
                }

                time++;
                }else{
                    if(temp.empty()) break;
                    time++;
                }
            }

            for(int x : temp){
                pq.push(x);
            }
        }

        return time;
    }
};
