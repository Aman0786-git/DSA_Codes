int findSubArraySum(vector<int>&arr, int n, int k)
{
	// code here
	/*
	For Positive Numbers Only
	int i=0,j=0,count=0,sum=0;
	 while(j<n){
	     sum+=arr[j];
	     if(sum<k)j++;
	     else if(sum==k)count++;
	     else {
	         while(sum>k)sum-=arr[i++];
	         if(sum==k)count++;
	     }
	     j++;

	 }
	 return count;*/

	map<int, int>mp;
	mp[0] = 1;
	int count = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{	sum += arr[i];
		int remove = sum - k;
		count += mp[remove];
		mp[sum] += 1;
	}

	return count;
}