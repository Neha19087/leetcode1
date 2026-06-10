// there are multiple questions possible on pascal's triangle
//The first row contains a single element 1.
//Each row has one more element than the previous row.
//Every row starts and ends with 1.

// we are asked to find the element at rth row and cth column
// in a pascal's triangle element at rth row and cth column is equal to (r-1)C(c-1)
// instead of finding factorials for ncr we can cut the starting elements and just multiply 
//remaining to get O(r) time complexity
class Solution {
public:
    int ncr(int n,int r){
        int ans=1;
        for (int i=0; i<r;i++){
            ans=ans*(n-i);
            ans= ans/(i+1);
        }
        return ans;
    }
    int pascalTriangleI(int r, int c) {
        int ans= ncr(r-1,c-1);
        return ans;
    }
};

// we can we asked to generate nth row
// one way is to use above method to generate each element and thus the row
//other method is to use an observation that starting column no from zero , element in ith 
// of nth row is obtained by multiplying previous element with (row-column index)/column index

vector<int> generateRow(int row){
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans= ans*(row-col)/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
// this function can be further used to generate whole pascal's triangle
vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>>ans;
    for(int i=1;i<=N;i++){
        ans.push_back(ansRow);
    }
    return ans;

}
//another way is to use the property that each interior element in pascal triangle is equal to summ of above 
//two elements
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr_ans;
        vector<int>arr1;
        arr1.push_back(1);
        arr_ans.push_back(arr1);
        if(numRows==1){
            return arr_ans;
        }
        for(int i=1;i<numRows;i++){
            vector<int>arr;
            arr.push_back(1);
            for(int j=1;j<i;j++){
                arr.push_back(arr_ans[i-1][j-1]+arr_ans[i-1][j]);
            }
            arr.push_back(1);
            arr_ans.push_back(arr);
        }
        
        return arr_ans;
    }
};
