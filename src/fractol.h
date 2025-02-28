/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:31 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/02/28 00:32:15 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_frac
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		frac_type;
	double	jul_cre;
	double	jul_cim;
}	t_frac;

// init
t_frac	*init_frac(void);

// cleanup
int		exit_fractal(t_frac *frac);

// input handling
int	choose_frac(t_frac *frac);

// typedef enum e_bool
// {
// 	FALSE,
// 	TRUE
// }	t_bool;

// typedef struct s_pipex
// {
// 	int		in_fd;
// 	int		out_fd;
// 	t_bool	here_doc;
// 	t_bool	is_invalid_infile;
// 	char	**cmd_paths;
// 	char	***cmd_args;
// 	int		cmd_count;
// }	t_pipex;

// typedef struct s_pps
// {
// 	int		**pipes;
// 	pid_t	*pids;
// }	t_pps;

// // initialize
// t_pipex	*init_pipex(void);
// int		alloc_cmd_paths(t_pipex *pipex);
// int		alloc_cmd_args(t_pipex *pipex);
// int		**init_pipes(t_pipex *pipex);
// t_pps	*init_pps(t_pipex *pipex);

// // cleanup
// void	free_pipex(t_pipex *pipex);
// void	free_array(char **array);
// void	free_pipes(int **pipes, int count);
// void	free_pps(t_pps *pps, int count);

// // input handling
// int		scan_input(int argc, char **argv, t_pipex *pipex, char **envp);
// int		get_args(t_pipex *pipex, char **temp, int i);
// char	*find_path(char **envp);
// char	*get_full_path(char **paths, const char *cmd);
// char	*find_executable(const char *cmd, char **envp);
// int		get_commands(int argc, char **argv, t_pipex *pipex, char **envp);

// // main
// void	ft_pipex(t_pipex *pipex, char **envp);

#endif