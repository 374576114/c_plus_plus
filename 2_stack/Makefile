obj = main.o stack_2.o

main : ${obj}
	g++ -o $@ ${obj}
main.o : main.cpp stack_2.h
	g++ -c $<
stack_2.o : stack_2.cpp stack_2.h
	g++ -c $<

.PHONY : clean
clean:
	rm ${obj} main
