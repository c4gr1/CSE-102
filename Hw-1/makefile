all:clean clear compile  run 

compile: main.c util.c util.h
	@echo "Compiling..."
	@gcc main.c util.c -c
	@gcc main.o util.o

run:
	@echo "Running the tests...."
	./a.out
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
	
clear:	
	@clear
