void (t_list **a, t_list **b, int argc)
{
	while (argc-- > 1)
	{
		chunk(a, b);



	}
}

chunk (t_list **a,t_list **b)
{
	bounds_chunk(*a);


}


bool bounds_chunk(t_list *a)
{
	int	max;
	int	min;
	int	portion;
	int	chunk;

	max = maximum(*lst);
	min = minimum(*lst);
	portion = (max - min) / 5;
	chunk = min + portion;
	if (a->content > min && a->content < chunk)
		return (true);
	else
		return (false);
}
