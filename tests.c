#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

// TODO: use the actual number assigned!
#define __NR_hello 548
#define COPY_SYSCALL 549

long hello_syscall(void) {
    return syscall(__NR_hello);
}
long data_copy(char* dest, char* src, int size) {
	return syscall(COPY_SYSCALL, dest, src, size);
}

int testing_hello_syscall() {
	long rv;
    rv = hello_syscall();
	
	if(rv < 0) {
        perror("Hello syscall failed");
		return 1;
    } else {
        printf("Hello syscall ran successfully, check dmesg output\n");
    }

	return 0;
}

int testing_data_copy_syscall() {
	char* src = "copied value!";
	int len = strlen(src);
	int string_length = sizeof(char) * strlen(src);
	char* dest = malloc(string_length + 1);
	
	if (data_copy(dest, src, string_length) != 0) {
		printf("There was an error!\n");
		return 1;
	}

	printf("Data was copied successfully, unsettting src ...\n");
	
	
	src = NULL;
	
	if (src == NULL) {
		printf("Src is null, shouldnt crash ...\n");
	}
	if (dest == NULL) {
		return 1;
	}
	
	dest[len] = '\0';
	printf("Copied Value: %s\n", dest);
	free(dest);
	dest = NULL;
	return 0;
}

int main() {
	printf("Testing Hello syscall: \n");
	if (testing_hello_syscall() == 0) {
		printf("Hello Syscall has passed! \n");
	}
	else {
		printf("Hello Syscall has failed! \n");
	}
	printf("\n");
	printf("Testing data copy syscall: \n");
	if (testing_data_copy_syscall() == 0) {
		printf("Data Copy Syscall has passed! \n");
	}
	else {
		printf("Data Copy Syscall has failed! \n");
	}
	
	return 0;
}