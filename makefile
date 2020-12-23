all: processor.c client.c
	gcc -o processor processor.c
	gcc -o client client.c

run:
	./processor & ./client

clean:
	rm processor
	rm client
	rm read_pipe
	rm write_pipe
