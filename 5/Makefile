obj := 3_stack.o main.o 5_queue.o

main : $(obj)
	g++ -o $@ $(obj)
3_stack.o : 3_stack.cpp 3_stack.h
	g++ -c $<
5_queue : 5_queue.cpp 5_queue.h
	g++ -c $<

.PHONY:clean
clean:
	rm main $(obj)

