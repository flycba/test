/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: flycba
 *
 * Created on 2017年3月5日, 下午9:59
 */

#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <stdlib.h>

#define OK      (0)
#define ERROR   (-1)

typedef struct stack{
    int value;
    struct stack *next;
}st_stack;

#define stack_handle st_stack**


int stackinit(stack_handle *handle);
int stackfree(stack_handle *handle);
int pust_handle(stack_handle handle ,int value);
int pop_handle(stack_handle handle ,int *value);
int getvalue_handle(stack_handle handle ,int *value);

int pust_nor(int value);
int pust_min();
int pop_min(int value_pop);
int pop_nor(int *pt_nor);

int pop(int *pt_value);
int pust(int value);
int getmin(int *pt_value);


#ifdef __cplusplus
}
#endif

#endif /* STACK_H */

