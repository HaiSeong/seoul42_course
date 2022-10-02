/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:42:45 by toni              #+#    #+#             */
/*   Updated: 2022/10/02 12:08:01 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "lexer_utils.h"

int	exit_on_syntax_error(void)
{
	ft_fprintf(STDERR_FILENO, "minishell: Invalid Syntax at token\n");
	set_err_code(EXIT_SYNTAX_ERROR);
	ft_free_split(get_lex_toks());
	return (EXIT_SYNTAX_ERROR);
}

static bool	is_correct_subshell(char *line, int i) // x
{
	while (i > 0 && line[i] && ft_isspace(line[i]))
		i--;
	if (i >= 0 && (line[i] != '&' && line[i] != '|'))
		return (false);
	return (true);
}

static bool	has_opening_bracket(char *line, int i) // x
{
	while (i > 0 && line[i] && line[i] != '(')
		i--;
	if (i >= 0 && line[i] != '(')
		return (false);
	return (true);
}

static int	count_subshell_chars(char *line, char c) // x
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{		
		if (line[i] == '\'')
			while (line[++i] && line[i] != '\'')
				;
		if (line[i] == '\"')
			while (line[++i] && line[i] != '\"')
				;
		if (line[i] == c)
			count++;
		if (line[i])
			i++;
	}
	return (count);
}

bool	is_valid_line_syntax(char *line)
{
	int	i;

	i = 0;
	if (count_subshell_chars(line, '(') != count_subshell_chars(line, ')')) // 괄호 = 빅쉘
		return (false);
	while (line[i])
	{
		if (line[i] == '\'')
			while (line[++i] && line[i] != '\'') // 작은따움표
				;
		if (line[i] == '\"')
			while (line[++i] && line[i] != '\"') // 큰따움표 
				;
		if (line[i] == '(')
			if (!is_correct_subshell(line, i - 1)) // x
				return (false);
		if (line[i] == ')')
			if (!has_opening_bracket(line, i - 1)) // x
				return (false);
		if (line[i] == ';' || line[i] == '\\') // 이것도 빅쉘
			return (false);
		if (line[i])
			i++;
	}
	return (true);
}
