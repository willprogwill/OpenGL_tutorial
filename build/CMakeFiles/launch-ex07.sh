#!/bin/sh
bindir=$(pwd)
cd /Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/ex07src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex07 
	else
		"/Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex07"  
	fi
else
	"/Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex07"  
fi
