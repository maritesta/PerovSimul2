# Simple setup for Perov studies

# Create your area
mkdir Perov

cd Perov

git clone git@github.com:crovelli/PerovSimul2.git

cd PerovSimul2

# Setup environment on lxpus
/bin/bash

[
# First time only

export LCGENV_PATH=/cvmfs/sft.cern.ch/lcg/releases

/cvmfs/sft.cern.ch/lcg/releases/lcgenv/latest/lcgenv -p LCG_96 --ignore Grid x86_64-centos7-gcc8-opt Geant4 > geant4_lxplus.sh
]

source geant4_lxplus.sh

# Compile
mkdir simplesetup_build

cd simplesetup_build

cmake3 -DGeant4_DIR=GEANT4__HOME ../simplesetup

make

# Run w/o visualization
./simplesetup run.in

# Run with visualization
./simplesetup visandrun.mac
