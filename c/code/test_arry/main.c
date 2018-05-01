/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flycba
 *
 * Created on 2017年3月16日, 下午7:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
const long int NUM1  =((long int)1024*1024*250);
const long int NUM2 =((long int)1024*1024*250*8+10);

/*
 * 
 */
int main(int argc, char** argv)
{

    char *a = NULL;
    long int *b = NULL;
    struct timeval start, end;
    printf("efdfdf\n");
    a = (char *)malloc(sizeof(char)*NUM2);
    gettimeofday( &start, NULL );
    if(NULL == a){
        return (EXIT_FAILURE);
    }
    b = (long int *)(a);
    for (long int i = 0;i < NUM1;i++){
        *(b+i) = i;
         
    }
    gettimeofday( &end, NULL );
    getchar();
    free(a);
    
    
    printf("TIME START:%ld.%ld\n",start.tv_sec,start.tv_usec);
    printf("TIME END  :%ld.%ld\n",end.tv_sec,end.tv_usec);
    printf("POINT     :%ld  \\:%ld  size:%ld\n",(long int)b,(long int)b%4,sizeof(int *));
    return (EXIT_SUCCESS);
}

