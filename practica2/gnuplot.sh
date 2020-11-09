#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficos/exponenciacion.eps"
set key left top
set xlabel "Orden de la Matriz"
set ylabel "Tiempo en microsegundos"
plot 'text/exponenciacion.txt' using 1:2 t "Exponeciacion" w l, 'text/exponenciacionDyV.txt' using 1:2 t "Divide y venceras" w l, 'text/exponenciacionDyVIterativo.txt' using 1:2 t "Divide y venceras iterativo" w l
_end_
