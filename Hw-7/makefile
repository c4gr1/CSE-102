all:clean clear compile  run 

compile: 1901042630.c 
	@echo "Compiling..."
	@gcc 1901042630.c -c
	@gcc 1901042630.o 

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
