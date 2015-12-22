obj := main.o 3_stack.o

main : ${obj} 3_stack.h
	g++ -o $@ ${obj}
main.o : main.cpp 3_stack.h
	g++ -c $<
3_stack.o : 3_stack.cpp 3_stack.h
	g++ -c $<

.PHONY : clean
clean :
	rm ${obj} main
