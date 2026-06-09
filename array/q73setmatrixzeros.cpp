//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// brute force method will be to iterate the whole matrix and mark the whole row and column containing 0 with say -1
//but it will take n^3 time complexity 

// better method will be to use two arrays to track rows and columns 
// the one for rows will have size n (no of rows) and element at ith position will turn 0 if any 
//element in the ith row is 0
// likewise array for columns will have m elements and element at jth position will turn 0 if any 
//element in the jth column is 0
// finally we will reiterate the matrix and turn that element 0 whose corresponding row array element or
// column array element is zero
// time complexity will be O(mn) and space O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size(); // no of rows
        int m= matrix[0].size(); // no of columns
        int row[n]={0};
        int col[m]={0};
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(row[i]==1||col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }        
    }
};

// using an optimal solution we can reduce space complexity to constant
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size(); // no of rows
        int m= matrix[0].size(); // no of columns
        int col0=1; //to store data about 0th column
        // will use first row and first column of the matrix to store data about the rows and columns to be turned
        // zero but [0][0] th element will be common for both 
        //therefore we will use an extra variable to store data about 0th column
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if (j==0){
                        col0=0;
                    }
                    else{
                        matrix[0][j]=0;
                    }
                }
            }
        }
        // we cant direcctly change the first row and column as they are used for storing data
        // we will change them at end
        for(int i=1;i<n;i++){
            for (int j=1;j<m;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        } 
        // as 0th row depends on [0][0] element and 0th column depends on col0 value we cant change the value of 
        // [0][0] element initially
        // therefore first changing 0th column according to [0][0] element 
        if (matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        } 
        if (col0==0){
            for (int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }      
    }
};