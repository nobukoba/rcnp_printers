#!/bin/bash

#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_acc4150.txt  > drm_per_acc4150.txt 
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_a2c3540.txt 	> drm_per_a2c3540.txt 
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_ri1c2250.txt	> drm_per_ri1c2250.txt
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_rbc4150.txt 	> drm_per_rbc4150.txt 
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_rcc4000a.txt	> drm_per_rcc4000a.txt
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_rcc4000b.txt	> drm_per_rcc4000b.txt
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_h1c3540.txt 	> drm_per_h1c3540.txt 
#awk '{printf ("%s %s %d %d %d %d\n", $1, $2, (10-$3)*10, (10-$4)*10, (10-$5)*10, (10-$6)*10)}' drm_g1c2250.txt  > drm_per_g1c2250.txt 

awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_acc4150.txt  > btl_per_acc4150.txt 
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_a2c3540.txt  > btl_per_a2c3540.txt 
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_ri1c2250.txt > btl_per_ri1c2250.txt
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_rbc4150.txt  > btl_per_rbc4150.txt 
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_rcc4000a.txt > btl_per_rcc4000a.txt
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_rcc4000b.txt > btl_per_rcc4000b.txt
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_h1c3540.txt  > btl_per_h1c3540.txt 
awk '{if($3>0){btl=0}else{btl=100}; printf ("%s %s %d\n", $1, $2, btl);}' btl_g1c2250.txt  > btl_per_g1c2250.txt 
