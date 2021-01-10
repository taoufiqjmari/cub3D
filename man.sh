#!/bin/sh

PS3='Please enter your choice: '
options=("mlx.1" "mlx_new_window.1" "mlx_pixel_put.1" "mlx_new_image.1" "mlx_loop.1")
select opt in "${options[@]}"
do
    case $opt in
        "mlx.1")
            man /usr/share/man/man3/mlx.1
            break
            ;;
        "mlx_new_window.1")
            man /usr/share/man/man3/mlx_new_window.1
            break
            ;;
        "mlx_pixel_put.1")
            man /usr/share/man/man3/mlx_pixel_put.1
            break
            ;;
        "mlx_new_image.1")
            man /usr/share/man/man3/mlx_new_image.1
            break
            ;;
        "mlx_loop.1")
            man /usr/share/man/man3/mlx_loop.1
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done