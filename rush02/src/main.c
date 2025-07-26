#include "include/rush02.h"

void ft_parse(struct s_my_struct *dict)
{
	dict->my_var = 20;
}

int main()
{

	struct s_my_struct S1;
	S1.my_var = 10;
	S1.my_string = "salut";
	S1.my_char = 's';
	
	printf("HELLO WORLD!\n");
	printf("%d\n%s\n%c\n", S1.my_var, S1.my_string, S1.my_char);
	ft_parse(&S1);
	printf("%d\n%s\n%c", S1.my_var, S1.my_string, S1.my_char);
}
