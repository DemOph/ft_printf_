#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *tab;
	if (!(tab = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return(tab);
}
int	is_empty(t_list	*liste)
{
	if (liste == NULL)
		return (0);
	return (1);
}
void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (is_empty(*alst) == 1 && new)
		new->next = *alst;
	*alst = new;
}

int main()
{
	int i = 1;
	t_list **alst;

	t_list *p1, *p2, *new, *new2;
	new = ft_lstnew("ana khsni nun lawal\n");
	new2 = ft_lstnew("ana ri bghito tzidoni fi lwl\n");
	p1 = ft_lstnew("ana knt tani nut wlit talt\n");
	p2 = ft_lstnew("ama knt lwl but wlit tani\n");
	p2->next = p1;
	/*while (p2)
	 *	{
	 *			printf("elemt of the list %d, = %s\n", i, p2->content);
	 *					p2 = p2->next;
	 *							i++;
	 *								}*/
	i = 1;
	alst = &p2;
	ft_lstadd_front(alst, new);
	alst = &new;
	ft_lstadd_front(alst, new2);
	printf("AFTER :\n");
	while (*alst)
	{
		printf("ELEMT of the list  %d, %s", i, (*alst)->content);
		*alst = (*alst)->next;
		i++;
	}
}
