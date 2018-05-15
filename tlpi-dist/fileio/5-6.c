#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"


int main(int argc,char* argv[])
{
    int fd1,fd2,fd3;
    ssize_t writenum;
    off_t ret;

    if(2 != argc||strcmp(argv[1],"--help")==0)
        usageErr("%s openfile\n",argv[1]);

    fd1 = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
    if(-1 == fd1)
        errExit("open fd1");

    fd2 = dup(fd1);
    if(-1 == fd2)
         errExit("dup fd2");
       
    fd3 = open(argv[1],O_RDWR);
    if(-1 == fd3)
        errExit("open fd3");

    writenum = write(fd1,"hello",6);
    if(-1 == write)
        errExit("write hello");
    writenum = write(fd2,"world--------",10);
    if(-1 == write)
        errExit("write hello");

    ret = lseek(fd2,0,SEEK_SET);
    if(-1  == ret)
        errExit("lseek");

    writenum = write(fd1,"HELLO",6);
    if(-1 == write)
        errExit("write hello");
    writenum = write(fd2,"GIDDAY",6);
    if(-1 == write)
        errExit("write hello");


    if(close(fd1)==-1)
        errExit("close fd1");
    if(close(fd2)==-1)
        errExit("close fd2");
    if(close(fd3)==-1)
        errExit("close fd3");

    exit(EXIT_SUCCESS);

}

