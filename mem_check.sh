#!/bin/sh

valgrind -s --leak-check=full --show-reachable=yes --track-origins=yes ./prog
