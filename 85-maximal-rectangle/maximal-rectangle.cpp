class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Create heights array for histogram
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        // Process each row
        for (int i = 0; i < rows; i++) {
            // Update heights array
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Calculate maximum rectangle area for current histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {

            // Use 0 as sentinel value for the last bar
            int currHeight = (i == n) ? 0 : heights[i];
            
            // While stack is not empty and current height is less than top of stack
            while (!st.empty() && currHeight < heights[st.top()]) {
                
                int height = heights[st.top()];
                st.pop();
                
                // Calculate width
                int width;
                if (st.empty()) {
                    width = i;
                } 
                else {
                    width = i - st.top() - 1;
                }
                
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};