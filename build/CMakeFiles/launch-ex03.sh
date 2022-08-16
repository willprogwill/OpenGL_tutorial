#!/bin/sh
bindir=$(pwd)
cd /Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/ex03src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex03 
	else
		"/Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex03"  
	fi
else
	"/Users/ryokokubun/Documents/school/Q2/3dGPU/glsl_tutorial/build/ex03"  
fi
