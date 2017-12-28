#!/bin/sh
#make clean -j 24
#echo "make clean done!"
make dist -j 24 PYTHON_PREFIX_ARG=
echo "make dist done!"
make install PYTHON_PREFIX_ARG=
echo "make install done!"
