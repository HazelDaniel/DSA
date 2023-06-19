#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int *find_max_cross_sum (int *sum_nums, int low, int mid, int high);
int *find_max_sub_array (int* nums, int low, int high);
int maxSubArray(int* nums, int numsSize);

int main (void)
{
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4}, max_sum;
	max_sum = maxSubArray(nums, 9);
	printf("The max sum is %d\n", max_sum);
	return EXIT_SUCCESS;
}

int maxSubArray(int* nums, int numsSize){
  int *max_arr = find_max_sub_array(nums, 0, numsSize), max_sum;
  max_sum = max_arr[2];
  free(max_arr);
  return max_sum;
}
int *find_max_sub_array (int* nums, int low, int high)
{
  int *temp_arr = (int *)malloc((3) * sizeof(int));
  int *left_arr = (int *)malloc((3) * sizeof(int));
  int *right_arr = (int *)malloc((3) * sizeof(int));
  int *cross_arr = (int *)malloc((3) * sizeof(int));
  int mid, left_low, left_high, left_sum, cross_low, cross_high, cross_sum, right_low, right_high, right_sum;

  if (low == high)
  {
    temp_arr[0] = nums[low];
    temp_arr[1] = nums[low];
    temp_arr[2] = nums[low];
    return temp_arr;
  }
  else if (low < high)
  {
    mid = (high + low) / 2;
    left_arr = find_max_sub_array(nums, low, mid);
    right_arr = find_max_sub_array(nums, mid + 1, high);
    cross_arr = find_max_cross_sum(nums, low, mid , high);
    if (left_arr[2] >= right_arr[2] && left_arr[2] >= cross_arr[2])
		{
				free(temp_arr), free(right_arr), free(cross_arr);
				return left_arr;
		}
    else if (right_arr[2] >= left_arr[2] && right_arr[2] >= cross_arr[2])
		{
			free(temp_arr), free(left_arr), free(cross_arr);
			return right_arr;
		}
    else
		{
			free(temp_arr), free(right_arr), free(left_arr);
      return cross_arr;
		}
  }
	return temp_arr;
}
int *find_max_cross_sum (int *sum_nums, int low, int mid, int high)
{
  int sum = 0, left_sum = INT_MIN, right_sum, i;
  int max_left = -1, max_right;
  int *temp_arr = (int *)malloc(3 * sizeof(int));

  for (i = mid; i >= 0; i--)
  {
    sum += sum_nums[i];
    if (sum >= left_sum)
		{
      left_sum = sum;
			max_left = i;
		}
  }

  sum = 0;
  right_sum = INT_MIN;
  max_right = -1;

  for (i = mid + 1; i <= high; i++)
  {
    sum += sum_nums[i];
    if (sum >= right_sum)
		{
      right_sum = sum;
			max_right = i;
		}
  }

  temp_arr[0] = max_left, temp_arr[1] = max_right, temp_arr[2] = left_sum + right_sum;
  return temp_arr;
}
