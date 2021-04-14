#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int token;				// curren token
char *src, *old_src;	// pointer to source code string
int poolsize;			// default size of text/data/stack
int line;				// line number
#define int long long	// work with 64-bit target

void next()					// �ʷ����� 
{
	token = *src++;		// Ϊʲô���� token ��Ϊ char ? 
	return;
}

void expression(int level)	// ���ڽ���һ�����ʽ
{
	// do something
	return;
}

void program()				// �﷨��������ڣ��������� C ���Գ���
{
	next();
	while(token > 0)
	{
		printf("token is %c\n", token);
		next();
	}
	return;
}

int eval()					// ���������ڣ����ڽ���Ŀ�����
{
	// do something
	return 0;
}

int main(int argc, char **argv)
{
	int read_bytes, fd;
	
	argc--;
	argv++;
	
	line = 1;
	poolsize = 256  * 1024;	// arbitrary size
	
	if((fd = open(*argv, 0)) < 0)	// fd = file descriptor, return -1 if open failed
	{
		printf("could not open(%s)\n", *argv);
        return -1;
	}
	
	if(!(src = old_src = malloc(poolsize)))
	{
		printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
	}
	
	// read the source file
	if(read_bytes = read(fd, src, poolsize - 1) <= 0)
	{
		printf("read() returned %d\n", read_bytes);
        return -1;
	}
	
	src[read_bytes] = '/0';
	close(fd);
	
	program();
	return eval();
} 
