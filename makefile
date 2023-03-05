all: helloworld
helloworld: helloworld.c
	gcc -Wall -Werror -o helloworld helloworld.c
clean:
	rm helloworld
run:
	./helloworld
