#!/bin/sh
cc -Os -Wall fossil_delta.c fdelta.c -o fdelta
cc -Os -Wall fossil_delta.c fapply.c -o fapply
