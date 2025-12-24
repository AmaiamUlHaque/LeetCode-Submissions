class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> numMap;

        int n = nums.size();
        for (int i=0; i<n; i++){
            int conjugate = target-nums[i];

            if (numMap.count(conjugate)){
                return {numMap[conjugate],i};
            }

            numMap[nums[i]] = i;
        }

        return{0}; //not possible --> solution garunteed


        // PREV ANS
        // for  (int i=0; i<nums.size()-1; i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         if (nums[i]+nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {0}; //not possible

    }

};