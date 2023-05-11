/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:01:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/12/20 16:02:00 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_parsed {
	int				empty;
	char			**cmds;
	char			**redirections;
	int				cmds_quant;
	int				redir_quant;
	int				hdocs_quant;
	struct s_parsed    *next;
}                    t_parsed;
