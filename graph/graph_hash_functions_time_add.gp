set terminal pdf color enhanced font 'Calibri,16' size 20cm,16cm
set output 'graph_hash_functions_time_add.pdf'
set key inside left top font 'Calibri,16'
set colorsequence podo
set style line 1 lc rgb 'blue' lw 1 pt 5 ps 0.5
set style line 2 lt 1 lw 2 pt 2 ps 0.5
set style line 3 lt 2 lw 2 pt 3 ps 0.5
set style line 4 lt 4 lw 2 pt 5 ps 0.5
set style line 5 lt 5 lw 2 pt 7 ps 0.5
set style line 6 lt 6 lw 2 pt 9 ps 0.5
set style line 7 lt 7 lw 2 pt 13 ps 0.5
set style line 8 lt 8 lw 2 pt 3 ps 0.5
set style line 9 lt 9 lw 2 pt 5 ps 0.5
set style line 10 lt 10 lw 1 pt 7 ps 0.5
set style line 11 lt 11 lw 1 pt 9 ps 0.5
set style line 12 lt 12 lw 1 pt 13 ps 0.5
set style line 13 lt 13 lw 1 pt 3 ps 0.5
set style line 14 lt 14 lw 1 pt 5 ps 0.5
set style line 15 lt 15 lw 1 pt 7 ps 0.5
set style line 16 lt 16 lw 1 pt 9 ps 0.5
set xlabel "Количество элементов" font 'Calibri,16'
set ylabel "Время, с" font 'Calibri,16'
set xtics 200000

plot 'Hash function KRHash.dat' using 2:3 title "KRHash" with linespoints ls 1,\
     'Hash function ELFHash.dat' using 2:3 title "ELFHash" with linespoints ls 2,\
     'Hash function jen.dat' using 2:3 title "jen" with linespoints ls 3,\
     'Hash function djb2.dat' using 2:3 title "djb2" with linespoints ls 4,\
     'Hash function fnvHash.dat' using 2:3 title "fnvHash" with linespoints ls 5
     


