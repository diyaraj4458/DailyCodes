class Solution {
    int maxArea(vector<int> row){
        sort(row.begin(),row.end(),greater<int>());
        int ans=0;
        for(int i=0;i<row.size();i++){
            int temp=row[i]*(i+1);
            ans=max(ans,temp);
        }
        return ans;
    }
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> temp(n,0);
        int ans=0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    temp[j]=0;
                }
                else{
                    temp[j]++;
                }
            }
            ans=max(ans,maxArea(temp));
        }
        return ans;
    }
};