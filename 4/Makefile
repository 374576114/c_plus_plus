obj := 4_queue.o main.o

main : ${obj}
	g++ -o $@ ${obj}
main.o : main.cpp 4_queue.h
	g++ -c $<
4_queue.o : 4_queue.cpp 4_queue.h
	g++ -c $<

.PHONY:clean
clean:
	rm ${obj} main
