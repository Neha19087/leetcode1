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

// we have to rotate the matrix by 90 degree 
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]
// brute method will be to observe the swaps and notice where each element is going
// but this method uses an extra space of matrix
// [i][j]--> [j][n-1-i]
// to do it in constant place we can first take its transpose and then reverse each row to get
// the desired rotation without using extra space
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n-1;i++){
            for (int j=i+1;j<n;j++){   // only above the diagonal elements are swapped
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n/2;j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }   
    }
};

// we have to print the mattrix in a spiral manner
// it can only be done using one approach but we have to make sure to consider edge cases
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int>arr;
        int top=0;
        int left=0;
        int right= m-1;
        int bottom= n-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                arr.push_back(matrix[top][i]);
            }
            top++;
            for (int i=top;i<=bottom;i++){
                arr.push_back(matrix[i][right]);
            } 
            right--;
            if (top<=bottom){
                for(int i=right;i>=left;i--){
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return arr;
    }
};