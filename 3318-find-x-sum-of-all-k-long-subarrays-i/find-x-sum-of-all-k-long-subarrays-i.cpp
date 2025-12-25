class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int answerLength = n - k + 1;
        vector<int> answer(answerLength); 
        vector<int> freq(51, 0);

        // Initialize first window
        for (int j = 0; j < k; j++) {
            freq[nums[j]]++;
        }

        for (int i = 0; i < answerLength; i++) {
            // Create a list of (number, frequency) pairs
            vector<pair<int, int>> elements;
            for (int num = 1; num <= 50; num++) {
                if (freq[num] > 0) {
                    elements.push_back({num, freq[num]});
                }
            }
            
            // Sort by frequency (descending), then by number (descending)
            sort(elements.begin(), elements.end(), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    if (a.second != b.second) {
                        return a.second > b.second;
                    }
                    return a.first > b.first;
                });
            
            // Calculate x-sum
            int sum = 0;
            int count = min(x, (int)elements.size());
            for (int j = 0; j < count; j++) {
                sum += elements[j].second * elements[j].first;
            }
            answer[i] = sum;
            
            // Slide window
            if (i < answerLength - 1) {
                freq[nums[i]]--;
                freq[nums[i + k]]++;
            }
        }
        
        return answer;
    }
};

// class Solution { //only my smol brain
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
        
//         int n = nums.size();

//         answerLength = n-k+1;
//         vector<int> answer(answerLength); 
//         vector<int> freq(50);


//         for (int j = 0; j<k; j++){ //for initial subarray

//             freq[nums[j]]++; //keeps track of the current subarray's frequencies

//         }


//         for (int i = 1; i<answerLength; i++){ //for each index of answer after 0

//             freq[nums[i-1]]--; //remove the previous' subarray's initial element
//             freq[nums[i+k]]++; //add the current' subbarray's last element

//             // calculates which are the top x most frequent elements
//             // NEED HELP HERE
            
//             // calculates answer[i] via sum of all elements*theirFrequencies
//             for (i=0; i<x; i++){
//                 answer[i] += freqElement[i]*freq[freqElement[i]]
//             }
//         }
        
//     }
// };


// class Solution { //idk chat gpt but i dont like it
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         int n = nums.size();
//         vector<int> answer(n - k + 1);
        
//         for (int i = 0; i <= n - k; i++) {
//             vector<int> freq(51, 0);
            
//             // Count frequencies
//             for (int j = i; j < i + k; j++) {
//                 freq[nums[j]]++;
//             }
            
//             // Create index array [1, 2, 3, ..., 50]
//             vector<int> indices(50);
//             for (int idx = 0; idx < 50; idx++) {
//                 indices[idx] = idx + 1;
//             }
            
//             // Sort indices based on frequency then value
//             sort(indices.begin(), indices.end(), [&](int a, int b) {
//                 if (freq[a] != freq[b]) {
//                     return freq[a] > freq[b];
//                 }
//                 return a > b;
//             });
            
//             // Calculate x-sum
//             int sum = 0;
//             for (int idx = 0; idx < x && freq[indices[idx]] > 0; idx++) {
//                 sum += freq[indices[idx]] * indices[idx];
//             }
            
//             answer[i] = sum;
//         }
        
//         return answer;
//     }
// };