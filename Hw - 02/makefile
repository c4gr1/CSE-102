all: clear clean compile run

compile: main.c util.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c util.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o

clear:
	@clear
