#used as an easy way to compile the function
all: voltMain.c voltFunc.c voltFunc.h #creates the voltMain file
	gcc voltMain.c voltFunc.c voltFunc.h -lm -o voltMain
