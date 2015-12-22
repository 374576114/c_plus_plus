obj := main.o 1_stack.o

main : ${obj}
	g++ -o $@ ${obj}
main.o : main.cpp 1_stack.h
	g++ -c $<
1_stack.o : 1_stack.cpp 1_stack.h
	g++ -c $<

.PHONY : clean
clean :
	rm main ${obj}
