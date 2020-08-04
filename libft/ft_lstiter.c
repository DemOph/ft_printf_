#include "libft.h"

void f(void *lst)
{
	((t_list *)lst)->content = ft_strdup("test");
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{

	if (lst == NULL)
		return ;
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}

int main()
{
	t_list *a, *b, *c, *d;
	a = ft_lstnew(ft_strdup("1"));
	b = ft_lstnew(ft_strdup("2"));
	c = ft_lstnew(ft_strdup("3"));
	d = ft_lstnew(ft_strdup("forth"));

	c->next = d;
	b->next = c;
	a->next = b;
	ft_lstiter(a, f);
	int i = 1;
	while(a)
	{
		printf("elmnt of list number %d : %s\n", i, a->content);
		a = a->next;
		i++;
	}
}
