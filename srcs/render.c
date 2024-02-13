/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:30:52 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/13 14:26:13 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct t_thread_data {
  pthread_t thread;	
  t_program *state;
  int start;
  int end;
} t_thread_data;


void	render_chunk(t_program *fractol, int start, int end);

void *spawn_render_thread(void *data) {
  t_thread_data   *tdata;

  tdata = (t_thread_data *)data;
  render_chunk(tdata->state, tdata->start, tdata->end);
  return (NULL);
}

void	render(t_program *fractol)
{
	t_thread_data threads[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; i++)
	{
		threads[i].state = fractol;
		threads[i].start = i * (WIN_HEIGHT * WIN_WIDTH / THREAD_NUM);
		threads[i].end = threads[i].start + (WIN_HEIGHT * WIN_WIDTH / THREAD_NUM);
		pthread_create(&threads[i].thread, NULL, spawn_render_thread, &threads[i]);
	}
	for (int i = 0; i < THREAD_NUM; i++)
		pthread_join(threads[i].thread, NULL);
}


void	render_chunk(t_program *fractol, int start, int end)
{
	unsigned int	color;
	int				escape_time;

	for (; start < end; start++)
	{
			t_point point = (t_point){.x = start % WIN_WIDTH, .y = start / WIN_WIDTH};
			escape_time = pthread_escape_time_julia(MAX_ITER, fractol, &fractol->mouse_pos, point);
			if (MAX_ITER == escape_time)
				color = 0;
			else
				color = escape_time * fractol->algo_toggle;
			pixel_put(&fractol->img, point, color % 0xFFFFFFFF);
	}
}
