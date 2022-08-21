int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* return_array = (int*)malloc(sizeof(int) * 2);
    int sum_temp = 0;

    if (return_array == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < (numsSize - 1); i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum_temp = nums[i] + nums[j];
            if (sum_temp == target)
            {
                *returnSize = 2;
                return_array[0] = i;
                return_array[1] = j;
                return return_array;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}//±©Á¦Ëã·¨