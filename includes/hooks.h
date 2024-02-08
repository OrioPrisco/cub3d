/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:59:19 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/02/08 17:58:42 by mpeulet          ###   ########.fr       */
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
void	tick_doors(t_env *env);
void	door_interact(t_env *env);

void	animate_sprite(t_env *env);
#endif
