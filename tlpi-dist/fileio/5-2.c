#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"


void main (int argc,char* argv[])
{
	int fd;
	off_t ret;
	ssize_t writenum;
	char buf[32]="\nhahaha\n";

	if(argc != 2||strcmp(argv[1],"--help") == 0)
		usageErr("%s file\n",argv[0]);

	fd = open(argv[1],O_APPEND|O_WRONLY);
	if(-1 == fd)
		errExit("open");
	
	ret = lseek(fd,0,SEEK_SET);
	if(-1 == ret)
		errExit("lseek");

	writenum = write(fd,buf,sizeof(buf));
	if (-1 == write)
		errExit("write");
	

	
	exit(EXIT_SUCCESS);
}
