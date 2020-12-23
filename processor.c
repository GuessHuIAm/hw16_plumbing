#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	int fd1;
	int fd2;
	int input;
	int output;

	while(1){
		fd1 = open("read_pipe", O_RDONLY);
		read(fd1, &input, sizeof(input));
		close(fd1);

 		output = input * input;

		fd2 = open("write_pipe", O_WRONLY);
		write(fd2, &output, sizeof(output));
		close(fd2);
	}
	return 0;
}
