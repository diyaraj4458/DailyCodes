class Solution{
	public:
		int findSmallestInteger(vector<int>& nums,int value){
			int n=nums.size();
			vector<int> v(value+1,0);
			for(int i:nums){
				int x=abs(i)%value;
				if(i>=0||x==0){
					v[x]++;
					}
				else{
					v[value-x]++;
					}
				}
				for(int i=0;i<=n-1;i++){
					int mod=abs(i)%value;
					if(v[mod]==0){
						return i;
					}
					v[mod]--;
				}
				
			
			return n;
		}
};