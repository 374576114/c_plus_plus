obj := 3_stack.o 6_queue.o main.o

main : ${obj}
	g++ -o $@ ${obj}
3_stack.o : 3_stack.cpp 3_stack.h
	g++ -o $@ -c $<
6_queue.o : 6_queue.cpp 6_queue.h
	g++ -o $@ -c $<
main.o : main.cpp
	g++ -o $@ -c $<

.PHONY : clean
clean:
	rm ${obj} main
