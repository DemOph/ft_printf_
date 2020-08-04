#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = (*alst);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int main()
{
	t_list *p1, *p2, *p3, *new;
	int i = 1;
	p1 = ft_lstnew("lawal");
	p2 = ft_lstnew("tani");
	p3 = ft_lstnew("talt");
	new = ft_lstnew("li rnzidoh");
	p1->next = p2;
	p2->next = p3;
	ft_lstadd_back(&p1, new);
	while (p1)
	{
		printf ("elmnt of list %d  %s\n", i, p1->content);
		p1 = p1->next;
		i++;
	}
}
