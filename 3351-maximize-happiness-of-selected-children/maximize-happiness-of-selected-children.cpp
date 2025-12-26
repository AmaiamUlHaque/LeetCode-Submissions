/*
basically
order the happiness from highest to lowest
then choose in that order while decrementing each of the remaining children's by one

can add each iterating happiness while decrementing the possible total by 
    - 0,1,2,3,... each iteration
instead of looping thru happiness array again
*/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Use nth_element to partially sort
        nth_element(happiness.begin(), happiness.begin() + k, happiness.end(), greater<int>());
        
        // Now sort only the first k elements
        sort(happiness.begin(), happiness.begin() + k, greater<int>());
        
        long long maxSum = 0;
        
        for (int i = 0; i < k; i++) {
            maxSum += max(happiness[i] - i, 0);
        }
        
        return maxSum;
    }
};