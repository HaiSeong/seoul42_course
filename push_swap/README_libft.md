
### libft

<br>

>ft_atolli : 문자열을 long long int형으로 바꾼다.
- ft_atoi 함수를 변형
``` c
long long int	ft_atolli(const char *str)
{
	int				i;
	int				sign;
	long long int	sum;

	sum = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
}
```

<br>

>ft_isspace : 공백문자를 검사한다.
``` c
int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}
```

<br>

>ft_split_isspace : 공백문자를 기준으로 문자열을 나눈다.
- ft_split 함수를 변형
``` c
static size_t	word_count(char const *s)
{
	size_t	i;
	size_t	slen;
	size_t	count;

	slen = ft_strlen(s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || i + 1 == slen))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	make_strs(char **strs, char const *s)
{
	size_t	i;
	size_t	length;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			length = 0;
			while (!ft_isspace(s[i + length]) && i + length < ft_strlen(s))
				length++;
			strs[word] = ft_substr(s, i, length);
			if (strs[word] == NULL)
				return (word + 1);
			i += length;
			word++;
		}
	}
	return (0);
}

char	**ft_split_isspace(char const *s)
{
	char	**result;
	size_t	wc;
	size_t	i;
	size_t	malloc_error;

	i = 0;
	wc = word_count(s);
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	if (result == NULL)
		return (0);
	malloc_error = make_strs(result, s);
	if (malloc_error != 0)
	{
		while (i < malloc_error)
			free (result[i++]);
		free(result);
		return (0);
	}
	result[wc] = 0;
	return (result);
}
```

<br>
