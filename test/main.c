int		main(int argc, char **argv)
{
	(void)argv;
	int	ret = 0;
	int	true_ret = 0;
	argc++;
	wint_t c = 'c';
	char mb[] = "Grâve";
	wchar_t s[100];
	mbstowcs(s, mb, 100);
	//printf("Test %o , %o , %o\n", "123" "456" "159487");
	//	//printf("TRUE PRINTF: \n");
	//		//true_ret = printf(argv[1], ft_atoi(argv[2]), &j);
	//			printf("\ntrue printf : %c\n", c);
	//				//printf("\nMY|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	//					//ret = ft_printf(argv[1], ft_atoi(argv[2]), &j);
	//						ft_printf("\nmy printf : %c\n", c);
	//							ft_putchar('\n');
	//								printf ("RET = %d\nTRUE RET = %d\n", ret, true_ret);
	//									return (0);
	//									}
