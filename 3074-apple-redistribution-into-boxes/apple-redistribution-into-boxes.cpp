class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int i=0; i<apple.size(); i++){
            totalApples += apple[i];
        }

        int boxesUsed = 0;
        for (int i=capacity.size()-1; i>=0 && totalApples>0; i--){ 

            int highestIndex = 0;
            
            for (int j=0; j<=i; j++){
                if (capacity[j] > capacity[highestIndex]){
                    highestIndex = j;
                }
            }
            
            int temp = capacity[highestIndex];
            capacity[highestIndex] = capacity[i];
            capacity[i] = temp;

            totalApples -= temp;
            boxesUsed++;

        }

        return boxesUsed;

    }
};