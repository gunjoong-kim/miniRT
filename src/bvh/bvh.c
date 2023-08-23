#include "bvh.h"

int	random_int_mm(int min, int max);

t_hittable	*make_bvh(t_list *list)
{
	t_hittable		**hittables;
	t_hittable		*root;
	t_comparator	comparator;
	int				random_num;

	root = (t_hittable *)malloc(sizeof(t_hittable));
	hittables = list_to_hittable_arr(list);
	random_num = random_int_mm(0, 2);
	if (random_num == 0)
		comparator = compare_x;
	else if (random_num == 1)
		comparator = compare_y;
	else if (random_num == 2)
		comparator = compare_z;
	quick_sort(hittables, 0, ft_lstsize(list), comparator);
	// root->hit = aabb_hit;
	root->left = make_child_node();
	root->right = make_child_node();
	//root->b_box = aabb_b_box; left, right의 b_box를 사용하여 구해야함 확인 필요.
	return (root);
}
