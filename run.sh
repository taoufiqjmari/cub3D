#!/bin/sh

PS3='Please enter your choice: '
options=("clean && run" "debug" "clean")
select opt in "${options[@]}"
do
    case $opt in
        "clean && run")
            make fclean
            make
            make run
            break
            ;;
        "debug")
            make fclean
            make debug
            echo '\n\n===> Run Debugger (F5)\n\n'
            break
            ;;
        "clean")
            make fclean
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done