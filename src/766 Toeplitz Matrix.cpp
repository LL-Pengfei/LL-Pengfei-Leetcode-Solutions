//766. Toeplitz Matrix
//https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};

//Extra:
//Rabin Karp Algorithm
//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
//searching for a pattern in an array (may be multi-dimensional)
//essentially hash first, if hash value same then check individual elements
//however, must ensure rehashing is O(1) operation (pop the front one, add in the new one)


/*
interesting solutions on leetcoe, in discussion
Java Answers to the follow-ups (load partial row/column one time), the 3rd one beats 98% 
//Solution 1: simple traversal
public boolean isToeplitzMatrix(int[][] matrix) {
        int height = matrix.length, width = matrix[0].length;
        if (height<=1 || width<=1) return true;
        for (int i=1; i<height; i++){
            for (int j=1; j<width; j++){
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
//Solution 2: Load one row each time, store,compare (with the crietria stored in Queue) and update it row by row.
 public boolean isToeplitzMatrix(int[][] matrix) {
        if (matrix.length <= 1 || matrix[0].length <= 1) return true;
        Queue<Integer> q = new LinkedList<>();
        for (int i=matrix[0].length-1; i>=0; i--){ //set criteria
            q.add(matrix[0][i]);
        }
        for (int j=1; j<matrix.length; j++){ 
            q.poll();
            for (int k=matrix[j].length-1; k>0; k--){
                if (matrix[j][k] == q.poll()) // compare
                    q.add(matrix[j][k]);
                else
                    return false; 
            }
            q.add(matrix[j][0]);
        }
        return true;
    }
//Solution 3: Load a partial row/column each time, the length of "piece" is defined as variable 'step'
 public int min(int a, int b){
        return((a>b)?b:a);
    }
    
    public int max(int a, int b){
        return((a<b)?b:a);
    }
    
    public boolean isToeplitzMatrix(int[][] matrix) {
        int width = matrix[0].length; 
        int height = matrix.length; 
        int step = 3; //This step indicates the maximum length of 'piece' which can be loaded at one time.
        int size = 1;
        int index = width - 1; 
        
        while (index >= 0){ 
            size = min(index+1, step); 
            int[] memory = new int[size];
            for (int i=0; i<size; i++){
                memory[size-i-1] = matrix[0][index-i]; //set memory
            }
            for(int j=1; j<min(height,width); j++){ //check the related pieces of rows
                //set boundary 
                int rightbound = min(index+j, width-1);
                int leftbound = max(index-step+1+j, j);
                for(int m=0, n=leftbound; m<size&&n<=rightbound; m++, n++)
                    if(matrix[j][n] != memory[m])
                        return false;
            }
        index -= step;
        }
        
        index = 0;
        while (index < height){ //for the purpose of completeness, the criteria should include two sides of the matrix
            size = min(height-1-index, step);
            int[] memory = new int[size];
            for (int i=0; i<size; i++){
                memory[size-1-i] = matrix[height-index-1-i][0];
            }
            for (int j=1; j<min(height,width); j++){ 
                int upperbound = max(height-index-step+j,j+1);
                int lowerbound = min(height-index-1+j,height-1);
                for(int m=0, n=upperbound; m<size&&n<=lowerbound; m++, n++)
                    if(matrix[n][j] != memory[m])
                        return false;
            }
            index+=step;
        }
        
        return true;
    }




Java Solution for Follow-Up 1 & 2
Here are what I've thought so far, please let me know if you have any better ideas!
For the follow-up 1, we are only able to load one row at one time, so we have to use a buffer (1D data structure) to store the row info. When next row comes as a streaming flow, we can compare each value (say, matrix[i][j], i>=1, j>=1) to the "upper-left" value in the buffer (buffer[j - 1]); meanwhile, we update the buffer by inserting the 1st element of the current row (matrix[i][0]) to buffer at position 0 (buffer[0]), and removing the last element in the buffer.
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) return true;
        int row = matrix.length;
        int col = matrix[0].length;
        List<Integer> buffer = new LinkedList<>();
        for(int j = 0; j < col; j++) buffer.add(matrix[0][j]);
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(buffer.get(j - 1) != matrix[i][j]) return false;
            }
            buffer.remove(buffer.size() - 1);
            buffer.add(0, matrix[i][0]);
        }
        return true;
    }
}
For the follow-up 2, we can only load a partial row at one time. We could split the whole matrix vertically into several sub-matrices, while each sub-matrix should have one column overlapped. We repeat the same method in follow-up 1 for each sub-matrix.
For example:

[1 2 3 4 5 6 7 8 9 0]              [1 2 3 4]              [4 5 6 7]              [7 8 9 0]
[0 1 2 3 4 5 6 7 8 9]              [0 1 2 3]              [3 4 5 6]              [6 7 8 9]
[1 0 1 2 3 4 5 6 7 8]     -->      [1 0 1 2]       +      [2 3 4 5]       +      [5 6 7 8]
[2 1 0 1 2 3 4 5 6 7]              [2 1 0 1]              [1 2 3 4]              [4 5 6 7]
[3 2 1 0 1 2 3 4 5 6]              [3 2 1 0]              [0 1 2 3]              [3 4 5 6]


Java Solution, two follow ups solved as well
As for the follow ups, we only need to add counters to track which row and column an element is. Then map the values into a file.
Eventually, we can check if the values in the same file are equal.
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int index = i - j;
                if (!map.containsKey(i - j)) {
                    map.put(i - j, matrix[i][j]);
                } else {
                    if (matrix[i][j] != map.get(i - j)) return false;
                }
            }
        }
        return true;
    }
}
*/
