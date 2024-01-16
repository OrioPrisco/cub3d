/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:59:19 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/16 15:22:59 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

typedef struct s_env	t_env;

void	handle_held_keys(t_env *env);
int		on_keyrelease(int key, t_env *env);
int		on_keypress(int key, t_env *env);
int		my_loop_hook(t_env *env);
int		my_expose(t_env *env);
int		quit_prg(t_env *env);
void	register_hooks(t_env *env);
#endif
