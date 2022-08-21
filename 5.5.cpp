//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
typedef struct t_node
{
	int value;
	int pos;
	struct t_node* next;
}T_NODE;

typedef struct t_hash
{
	T_NODE* head;
}T_HASH;

void hash_free(T_HASH* hash_table, int num)
{
	for (uint32_t i = 0; i < num; i++)
	{
		if (hash_table[i].head)
		{
			T_NODE* node = hash_table[i].head;
			while (node)
			{
				T_NODE* next_node = node->next;
				free(node);
				node = next_node;
			}
		}
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	T_HASH* hash_table = (T_HASH*)malloc(sizeof(T_HASH) * numsSize);
	if (hash_table == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	for (uint32_t i = 0; i < numsSize; i++)
	{
		hash_table[i].head = NULL;
	}

	for (uint32_t i = 0; i < numsSize; i++)
	{
		T_NODE* node = (T_NODE*)malloc(sizeof(T_NODE));
		if (node == NULL)
		{
			hash_free(hash_table, numsSize);
			*returnSize = 0;
			return NULL;
		}

		uint32_t mod = abs(nums[i]) % numsSize;
		node->value = nums[i];
		node->pos = i;
		node->next = hash_table[mod].head;
		hash_table[mod].head = node;

		uint32_t expect = abs(target - nums[i]);
		uint32_t expect_mod = expect % numsSize;

		T_NODE* node_temp = hash_table[expect_mod].head;
		while (node_temp)
		{
			if ((node_temp->pos != i) && (node_temp->value + nums[i] == target))
			{
				int* return_nums = (int*)malloc(sizeof(int) * 2);
				if (return_nums == NULL)
				{
					hash_free(hash_table, numsSize);
					*returnSize = 0;
					return NULL;
				}

				return_nums[0] = node_temp->pos;
				return_nums[1] = i;
				*returnSize = 2;
				return return_nums;
			}
			else
			{
				node_temp = node_temp->next;
			}
		}
	}

	*returnSize = 0;
	return NULL;
}