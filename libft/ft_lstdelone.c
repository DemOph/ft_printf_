#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}
void del(void *a)
{
	free(a);
}
intmain()
{
	t_list *a, *c, *d, *new;
	a = ft_lstnew("lawal");
	new = ft_lstnew(ft_strdup("li khsni n7yd"));
	c = ft_lstnew("lawal");
	d = ft_lstnew("ana lakher");
	a->next = new;
	ft_lstadd_front(&a, c);
	ft_lstadd_back(&a, d);
	ft_lstdelone(new, del);
	int i = 1;
	while(c)
	{
		printf("elmnt of list number %d : %s\n", i, c->content);
		c = c->next;
		i++;
	}
}
