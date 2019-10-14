
#include "libft.h"
#include <stdio.h>

int		main()
{
	t_list *first;
	t_list *second;
	t_list *third;

	first = ft_lstnew("un");
	second = ft_lstnew("deux");
	third = ft_lstnew("trois");
	ft_lstadd_front(third, second);
	ft_lstadd_front(second, first);

	printf("%d\n", ft_lstsize(first));
}
