#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *head;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!(head = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&head, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		if (!(new_list = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}

void *f(void *lst)
{
	char *s = ft_strdup(lst);
	*s = *s + 1;
	return ((void *)s);
}

void del(void *lst)
{
	free(lst);
}

int main()
{
	t_list *a, *b, *c, *d, *temp, *head;
	a = ft_lstnew(ft_strdup("1"));
	b = ft_lstnew(ft_strdup("2"));
	c = ft_lstnew(ft_strdup("3"));
	d = ft_lstnew(ft_strdup("forth"));;
	c->next = d;
	b->next = c;
	a->next = b;
	temp = ft_lstmap(a, &f, &del);
	int i = 1;
	while(a)
	{
		printf("elmnt of list number %d : %s\n", i, a->content);
		a = a->next;
		i++;
	}
	printf("**********\n");
	i = 1;
	while (temp)
	{

		printf("elmnt of list number %d : %s\n", i, temp->content);

		temp = temp->next;
		i++;
	}
}
