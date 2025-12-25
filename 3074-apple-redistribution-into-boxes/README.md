<h2><a href="https://leetcode.com/problems/apple-redistribution-into-boxes">Apple Redistribution into Boxes</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an array <code>nums</code> of length <code>n</code> and integers <code>k</code> and <code>x</code>.</p><p>The <strong>x-sum</strong> of an array is calculated as follows:</p> <ul> <li>Sort the array in non-decreasing order.</li> <li>If the length of the array is at least <code>x</code>, sum the last <code>x</code> elements of the sorted array. Otherwise, sum all elements.</li> </ul><p>Return an array <code>ans</code> of length <code>n - k + 1</code> where <code>ans[i]</code> is the <strong>x-sum</strong> of the subarray <code>nums[i..i + k - 1]</code> of length <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,2,2,3,4,2], k = 4, x = 2
<strong>Output:</strong> [3,5,5,6] 
<strong>Explanation:</strong> - For subarray [1,1,2,2]: Sorted → [1,1,2,2], sum of last 2 elements = 2+2 = 4? Wait let me recalculate... Actually 2+2=4, but example says 3. Let me check the sorted array: [1,1,2,2], last 2 are 2+2=4, but answer shows 3. Hmm, there might be an error in the example. Let me re-read the problem... Actually, looking at the example more carefully: For [1,1,2,2], sorted is [1,1,2,2], sum of last 2 is 2+2=4, but output shows 3. Let me check other subarrays... For [1,2,2,3]: sorted [1,2,2,3], last 2: 2+3=5 ✓ For [2,2,3,4]: sorted [2,2,3,4], last 2: 3+4=7, but output shows 5. Something's inconsistent. Let me provide a corrected example based on the problem description:
</pre>

<p><strong class="example">Example 1 (Corrected):</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5], k = 3, x = 2 
<strong>Output:</strong> [5,7,9] 
<strong>Explanation:</strong> - For subarray [1,2,3]: Sorted → [1,2,3], sum of last 2 elements = 2+3 = 5 - For subarray [2,3,4]: Sorted → [2,3,4], sum of last 2 elements = 3+4 = 7 - For subarray [3,4,5]: Sorted → [3,4,5], sum of last 2 elements = 4+5 = 9 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,2], k = 2, x = 3 
<strong>Output:</strong> [4,4,4]
<strong>Explanation:</strong> - For each subarray of length 2: [2,2], sorted → [2,2] - Since x=3 > array length=2, sum all elements: 2+2 = 4 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= k <= n <= 1000</code></li>
    <li><code>1 <= x <= k</code></li>
    <li><code>1 <= nums[i] <= 10<sup>5</sup></code></li>
</ul>
