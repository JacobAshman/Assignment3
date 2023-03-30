all: voltMain.c voltFunc.c voltFunc.h #creates the assignment file
	gcc voltMain.c voltFunc.c voltFunc.h -lm -o voltMain
