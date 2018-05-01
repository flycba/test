/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flycba
 *
 * Created on 2017年3月4日, 下午1:17
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
 * 
 */
int main(int argc, char** argv)
{

    stack_handle stack1 = NULL;
    stack_handle stack2 = NULL;
    int ret = ERROR;
    ret = stackinit(&stack1);
    if (ERROR == ret) {
        printf("ERROR:stackinit stack1 fail!\n");
        return 0;
    }
    ret = pust_handle( stack1, 20);
    if (ERROR == ret) {
        printf("ERROR:stackinit stack1 fail!\n");
        return 0;
    }
    
    ret = stackfree(&stack1);
    if (ERROR == ret) {
        printf("ERROR:stackinit stack1 fail!\n");
        return 0;
    }
    
    ret = stackinit(&stack2);
    if (ERROR == ret) {
        printf("ERROR:stackinit stack2 fail!\n");
        return 0;
    }

    int value = -555555;
    pust(0);
    pust(5);
    pust(3);
    pust(2);
    pop(&value);
    pop(&value);
    pop(&value);
    pust(13);
    pop(&value);
    pop(&value);
    //getchar();
    return (EXIT_SUCCESS);
}

