ft_atoi
ft_putnbr

int main(int argc, char *argv[])
{
	int par1;
	int par2;

	if (argc == 4)
	{
		if (ft_check_num(argv[2]) && ft_check_op(argv[3]) && ft_check_num(argv[4]))
		{
			ft_putnbr(0); 
			par1 = ft_atoi(argv[1]);
			par2 = ft_atoi(argv[3]);
			if (argv[3] == '+')
				ft_add();
			else if (argv[3] == '-')
				ft_substract();
			else if (argv[3] == '/')
				ft_divide();
			else if (argv[3] == '*')
				ft_multiply();
			else if (argv[3] == '%')
				ft_modulate();
		}
		else
			ft_putstr("   ");
		
	}
}

void	ft_divide(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero") // \n??????
	}
}

int	ft_check_num(char *s)
{
	while()
}
int	ft_check_op(char c)
{
	if (c == '+' || c == '-' || c == '/'
		|| c == '*' || c == '%')
		return (1);
	else
		return (0);
}