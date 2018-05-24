@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2018a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2018a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=measurementLikelihood_mex
set MEX_NAME=measurementLikelihood_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2018a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for measurementLikelihood > measurementLikelihood_mex.mki
echo COMPILER=%COMPILER%>> measurementLikelihood_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> measurementLikelihood_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> measurementLikelihood_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> measurementLikelihood_mex.mki
echo LINKER=%LINKER%>> measurementLikelihood_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> measurementLikelihood_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> measurementLikelihood_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> measurementLikelihood_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> measurementLikelihood_mex.mki
echo OMPFLAGS= >> measurementLikelihood_mex.mki
echo OMPLINKFLAGS= >> measurementLikelihood_mex.mki
echo EMC_COMPILER=lcc64>> measurementLikelihood_mex.mki
echo EMC_CONFIG=optim>> measurementLikelihood_mex.mki
"C:\Program Files\MATLAB\R2018a\bin\win64\gmake" -j 1 -B -f measurementLikelihood_mex.mk
