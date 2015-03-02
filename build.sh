#!/bin/sh
rm -rf dist
mkdir dist
cc -Os -Wall fossil_delta.c fdelta.c -o dist/fdelta
cc -Os -Wall fossil_delta.c fapply.c -o dist/fapply
