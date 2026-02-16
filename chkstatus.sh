#!/bin/bash

rcnp_printers_dir=${HOME}/HTMLpub/rcnp_printers
pwd=${PWD}
cd ${rcnp_printers_dir}

./each_printer.sh acc4150   
./each_printer.sh acc2570   
./each_printer.sh a2c2570   
./each_printer.sh a2c3540   
./each_printer.sh a3c2570   
./each_printer.sh ri1c4000
./each_printer.sh rbc4150   
./each_printer.sh rcc2570a 
./each_printer.sh rcc2570b  
./each_printer.sh h1c3540   
./each_printer.sh h2c2570   
./each_printer.sh h3c2570   
./each_printer.sh h4c5570   
./each_printer.sh h5c2570   
./each_printer.sh h6c2570   
./each_printer.sh g1c4000   

cd ${pwd}
