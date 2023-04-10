#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main (void)
{
	int array1[] = {-2,1,-3,4,-1,2,1,-5,4};
	printf("%d\n", maxSubArray(array1,9));
	return 0;
}

int maxSubArray(int* nums, int numsSize)
{
    int i, curr_max = nums[0], glob_max = curr_max;
    for (i = 1; i < numsSize; i++)
    {
				curr_max = nums[i] >= curr_max + nums[i] ? nums[i] : curr_max + nums[i];
        if (glob_max < curr_max)
        {
            glob_max = curr_max;
        }
    }
		return glob_max;
}
