#include "libft.h"

int ft_lstsize(t_list *lst)
{
	t_list *temp;
	int i;

	temp = lst;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int main()
{
	t_list *p1, *p2, *p3;
	int i = 1;
	p1 = ft_lstnew("ha wa7d");
	p2 = ft_lstnew("ha jouj");
	p3 = ft_lstnew("ha tlata");
	p1->next = p2;
	p2->next = p3;
	printf("le nb des elmt of my list is : %d\n", ft_lstsize(p1));
	while (p1)
	{
		printf("elmt of the list nb %d, %s\n", i, p1->content);
		p1 = p1->next;
		i++;
	}
}
