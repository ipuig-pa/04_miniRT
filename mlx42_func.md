1S: struct stores: t_mlx *mlx (); also NULL check needed when init
S2: mlx_init(): pass width, height, name, re-sizable val(T/F)
S3: (mlx_image_t)* img = mlx_new_image(): pass PTR to mlx_t, W, H; create buffer
S4: mlx_image_to_window():(show img in window)pass PTR to mlx(mlx_t); img(mlx_image_t)from S3
S5: wrapper ft:
Exit on error (what i used in to save lines) to exit and clean
	void	ft_error_exit(t_fractol *fractol)
	{
		ft_printf("Errors in initialization");
		if (fractol->img != NULL)
			mlx_delete_image(fractol->mlx, fractol->img);
		if (fractol->mlx != NULL)
			mlx_terminate(fractol->mlx);
		if (fractol)
			fractol = NULL;
		exit(EXIT_FAILURE);
	}
Exit on Success:
	void	ft_exit(t_fractol *fractol)
	{
		mlx_close_window(fractol->mlx);
		if (fractol->img != NULL)
			mlx_delete_image(fractol->mlx, fractol->img);
		if (fractol->mlx != NULL)
			mlx_terminate(fractol->mlx);
		if (fractol)
			fractol = NULL;
		exit(EXIT_SUCCESS);
	}