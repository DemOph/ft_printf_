#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
int main()
{
	t_list *p1, *p2, *p3;
	p1 = ft_lstnew("laah");
	p2 = ft_lstnew("ana");
	p3 = ft_lstnew("corrector");
	//ft_lstadd_front(&p1, p2);
	p1->next = p2;
	p2->next = p3;
	//int i = 1;
	//while(p1)
	//{
	//printf ("%d %s\n", i, p1->content);
	//p1 = p1->next;
	//i++;
	//}
	printf("last elmnt is %s", (char*)ft_lstlast(p1)->content);
}
