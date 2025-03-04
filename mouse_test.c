#include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

// Mouse press event
int mouse_press(int button, int x, int y, t_data *data)
{
    (void)data;
    printf("Mouse Pressed: button=%d at (%d, %d)\n", button, x, y);
    return (0);
}

// Mouse release event
int mouse_release(int button, int x, int y, t_data *data)
{
    (void)data;
    printf("Mouse Released: button=%d at (%d, %d)\n", button, x, y);
    return (0);
}

// Mouse move event
int mouse_move(int x, int y, t_data *data)
{
    (void)data;
    printf("Mouse Moved: (%d, %d)\n", x, y);
    return (0);
}

// Close window event
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    printf("Window closed.\n");
    return (0);
}

// Main function
int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Mouse Test");

    // Register mouse events
    mlx_hook(data.win, 4, 1L << 2, mouse_press, &data);    // Mouse press
    mlx_hook(data.win, 5, 1L << 3, mouse_release, &data);  // Mouse release
    mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);     // Mouse movement
    mlx_hook(data.win, 17, 0, close_window, &data);        // Close window (X button)

    mlx_loop(data.mlx);
    return (0);
}
