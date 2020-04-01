all: makeObject makeLib compile
makeObject:
	@gcc -c assign3.c -o assign3.o
makeLib:
	@ar cr libarbprecision.a assign3.o
compile:
	@gcc -o mainfile main.c -L. -larbprecision -lm
exe:
	@./mainfile input.txt output.txt plot.png
clean:
	@rm ./mainfile
	@rm ./assign3.o
	@rm ./libarbprecision.a