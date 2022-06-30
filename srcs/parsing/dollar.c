while (str[i])
{
	if (str[i] == '$')
	{
		while (str[i] && ft_isspace(str[i]) == 0)
		{
			++j;
		}
		j += 1;
	}
	++i;
}
tmp = malloc(sizeof(char) * (ft_strlen(str) - j) + ft_strlen(env_get(dollar, env) + 1));
i = 0;
while (str[i])
{
	if (str[i] == '$')
	{
		while (str[i])
		{
			env_get...
		}
		i += j;
	}
	tmp[k] = str[i];
	++j;
	++k;
}
