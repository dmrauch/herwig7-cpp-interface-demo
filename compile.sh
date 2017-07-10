#!/bin/bash

## ----------------------------------------------------------------------------
## Prepare the appropriate environment by setting up your environment variables
## for:
##   - GCC
##   - boost
##
## Besides the usual environment variables, the variables 'THEPEG_PATH' and
## 'HERWIG_PATH' are needed.
##
## Please replace the module files and paths below with their appropriate
## counterparts for your setup.
## ----------------------------------------------------------------------------

## Genser installation of ThePEG 2.0.4 / Herwig 7.0.4
module unload gcc/4.9.2
module load gcc/4.7.2-external-x86_64-slc6
module load boost/1.53.0-external-x86_64-slc-gcc47
THEPEG_PATH=/afs/cern.ch/sw/lcg/external/MCGenerators_lcgcmt67c/thepeg/2.0.4/x86_64-slc6-gcc47-opt
HERWIG_PATH=/afs/cern.ch/sw/lcg/external/MCGenerators_lcgcmt67c/herwig++/7.0.4/x86_64-slc6-gcc47-opt

g++ \
 -I$THEPEG_PATH/include \
 -L$THEPEG_PATH/lib/ThePEG \
 -lThePEG \
 -I$HERWIG_PATH/include \
 -L$HERWIG_PATH/lib/Herwig \
 -l:Herwig.so -lHerwigAPI -l:HwSampling.so \
 -o Herwig7API Herwig7API.cxx

# -lHwRunDirectories