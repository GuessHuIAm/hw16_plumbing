#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	mkfifo("read_pipe", 0666);
	mkfifo("write_pipe", 0666);

	int fd1;
	int fd2;

	int input;
	int output;

	while(1){
		printf("I will square this number: ");
        	scanf("%d", &input);
		fd1 = open("read_pipe", O_WRONLY);
        	write(fd1, &input, sizeof(input));
		close(fd1);

		fd2 = open("write_pipe", O_RDONLY);
        	read(fd2, &output, sizeof(output));
		close(fd2);
        	printf("\nThe answer is %d!\n", output);
    	}

    	return 0;
}
