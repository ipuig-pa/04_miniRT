/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:19:05 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/10 11:14:46 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "linalg.h"
# include "scene.h"
# include "env.h"
# include "color.h"
# include "ray.h"
# include "gc.h"
# include "parser.h"
# include "hook.h"
# include "transform.h"
# include <unistd.h>// for open, close, read, write
# include <stdio.h> // for printf, perror
# include <stdlib.h>// for malloc, free, exit
# include <string.h> // for strerror
# include <math.h>// for math functions (requires -lm when compiling)
# include <fcntl.h>// for open flags like O_RDONLY, O_WRONLY, etc.
# include <stdbool.h>//to use bool variables
# include "../minilibx_macos/mlx.h" //minilibx macos
// # include "../minilibx-linux/mlx.h" //minilibx linux

#endif