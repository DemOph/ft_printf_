#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list*tmp;
	t_list*prev;

	tmp = *lst;

	printf("i am the address of new --> %p, and i am new --> %p\n", lst, *lst);
	while (tmp != (void *)0)
	{
		printf("elmnt of list ******  number : %s\n", tmp->content);
		(*del)(tmp->content);
		prev = tmp;
		(tmp) = (tmp)->next;
		free(prev);
	}
	free(tmp);
	*lst = NULL;
}
void del(void *a)
{
	free(a);
}

int main()
{
	t_list *a, *c, *fd,*d, *new;
	a = ft_lstnew("tani");
	new = ft_lstnew(ft_strdup("third"));
	c = ft_lstnew("lawal");
	d = ft_lstnew(ft_strdup("forth"));
	fd = ft_lstnew(ft_strdup("fifth"));

	//c->next = a;
	////a->next = new;
	////new->next = d;
	////d->next = fd;
	ft_lstadd_front(&a, c);
	ft_lstadd_back(&c, d);
	ft_lstadd_back(&c, fd);
	ft_lstclear(&new, del);
	a->next->next = NULL;
	int i = 1;
	while(c)
	{

		printf("i am c --> %p, and i am c->next --> %p\n", c, c->next);
		printf("elmnt of list number %d : %s\n", i, c->content);

		c = c->next;
		i++;
	}
}

//c a new d fd
