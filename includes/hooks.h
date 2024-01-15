/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:59:19 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/15 15:47:29 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

typedef struct s_env	t_env;

int	deal_key(int key, t_env *env);
int	my_loop_hook(t_env *env);
int	my_expose(t_env *env);
int	quit_prg(t_env *env);
#endif
