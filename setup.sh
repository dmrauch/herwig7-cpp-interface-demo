#!/bin/bash

## ----------------------------------------------------------------------------
## Prepare the appropriate environment by setting up your environment variables
## for:
##   - GCC
##   - boost
##   - HepMC
##   - FastJet
##   - LHAPDF
##   - Rivet
##   - ThePEG
##   - Herwig7
##
## Besides the usual environment variables, the variable 'HERWIG_PATH' is
## needed.
##
## Please replace the module files and paths below with their appropriate
## counterparts for your setup.
## ----------------------------------------------------------------------------

## Genser installation of ThePEG 2.0.4 / Herwig 7.0.4
module unload gcc/4.9.2
module load gcc/4.7.2-external-x86_64-slc6
module load boost/1.53.0-external-x86_64-slc-gcc47
module load hepmc/2.06.08-external-lcgcmt67c-x86_64-slc6-gcc47-opt
module load fastjet/3.0.3-external-lcgcmt67c-x86_64-slc6-gcc47-opt
module load lhapdf/6.1.4-external-lcgcmt67c-x86_64-slc6-gcc47-opt
module load rivet/2.4.2-external-lcgcmt67c-x86_64-slc6-gcc47-opt
export THEPEG_PATH=/afs/.cern.ch/sw/lcg/external/MCGenerators_lcgcmt67c/thepeg/2.0.4/x86_64-slc6-gcc47-opt
export HERWIG_PATH=/afs/.cern.ch/sw/lcg/external/MCGenerators_lcgcmt67c/herwig++/7.0.4/x86_64-slc6-gcc47-opt
export LD_LIBRARY_PATH=$THEPEG_PATH/lib/ThePEG:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$HERWIG_PATH/lib/Herwig:$LD_LIBRARY_PATH
