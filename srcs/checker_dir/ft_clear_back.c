/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:13:58 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:52:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 8, 30, 40, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 40, 5, 5, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_fail_1(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 0, 0, 0, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_fail_2(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_success_1(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 8, 30, 40, 255);
	SDL_RenderClear(visu->renderer);
}

void	ft_clear_success_2(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 40, 5, 5, 255);
	SDL_RenderClear(visu->renderer);
}
