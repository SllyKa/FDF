/*void			draw_linew(t_window *par, t_line *line)
{
	t_pointz	*pd;
	t_line		*ln;
	char		isswap;
	double		grad;
	double		y;

	double		xend;
	double		yend;
	//double		xgap;
	t_point		*x11;
	t_point		*x12;

	isswap = initswap(&ln, &pd, line);

	grad = 1;
	if (pd->x)
		grad = pd->y / pd->x;
	
	xend = round(ln->p0->x);
	yend = ln->p0->y + grad * (xend - ln->p0->x);
	xgap = 1 - ((ln->p0->x + 0.5) - floor(ln->p0->x + 0.5));
	x11 = init_tpoint(xend, (int)yend, ln->p0->clr);
	put_px_w(par, x11, isswap, (1 - (yend - (int)yend)) * xgap);
	x11->y = x11->y + 1;
	put_px_w(par, x11, isswap, ((yend - (int)yend)) * xgap);
	y = yend + grad;

	xend = round(ln->p1->x);
	yend = ln->p1->y + grad * (xend - ln->p1->x);
	xgap = 1 - ((ln->p1->x + 0.5) - floor(ln->p1->x + 0.5));
	x12 = init_tpoint(xend, (int)yend, ln->p1->clr);
	put_px_w(par, x12, isswap, (1 - (yend - (int)yend)) * xgap);
	x12->y = x12->y + 1;
	put_px_w(par, x12, isswap, ((yend - (int)yend)) * xgap);

	(x11->x)++;
	while(x11->x <= x12->x - 1)
	{
		x11->y = (int)y;
		put_px_w(par, x11, isswap, 1 - (y - (int)y));
		x11->y = (int)y + 1;
		put_px_w(par, x11, isswap, (y - ((int)y)));
		y = y + grad;
		(x11->x)++;
	}
	free(pd);
	free(ln->p0);
	free(ln->p1);
	free(ln);
}