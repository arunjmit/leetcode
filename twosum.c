#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

	int i, j;
	int *ret = malloc(sizeof(int) * 2);

	for ( i = 0; i < numsSize; ++i) {
		for (j = i + 1; j < numsSize; ++j) {

			if ((target - nums[j]) == nums[i]) {
				ret[0] = i;
				ret[1] = j;
				
				return ret;
			}
		}
	}
	return NULL;
			
}

int main ()
{
	int a[4] = { 2, 7,11, 15};

	int returnsize;

	int *ret;
	ret = twoSum(a, 5, 9, &returnsize);
	printf("%d, %d\n", ret[0], ret[1]);
	return 1;
}
