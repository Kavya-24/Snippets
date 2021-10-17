class Solution {
    public int maxSubArray(int[] nums) 
    {
	    int meh = 0,msf = Integer.MIN_VALUE; 
	    for(int i = 0;i<nums.length;i++)
	    {
	        meh = meh + nums[i];
	        if(meh < nums[i])
	            meh = nums[i];
	        if(meh > msf)
	            msf = meh;
	    }
	    return msf;
        
    }
}
