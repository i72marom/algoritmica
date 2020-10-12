#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficos/nlogn.eps"
set key right bottom
set xlabel "Número de elementos"
set ylabel "Tiempo"
plot 'text/nlogn.txt' using 1:3 t "Tiempos estimados" w l, 'text/nlogn.txt' using 1:2 t "Tiempos reales" w l
_end_

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficos/iterativo.eps"
set key right bottom
set xlabel "Orden de la matriz"
set ylabel "Tiempo"
plot 'text/iterativo.txt' using 1:3 t "Tiempos estimados" w l, 'text/iterativo.txt' using 1:2 t "Tiempos reales" w l
_end_

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficos/recursivo.eps"
set key right bottom
set xlabel "Orden de la matriz"
set ylabel "Tiempo"
plot 'text/recursivo.txt' using 1:3 t "Tiempos estimados" w l, 'text/recursivo.txt' using 1:2 t "Tiempos reales" w l
_end_
