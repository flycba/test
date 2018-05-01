/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.c
 * Author: flycba
 *
 * Created on 2017年3月5日, 下午10:00
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

st_stack *Nor_stack = NULL;
st_stack *Min_stack = NULL;

int getmin(int *pt_value)
{
    if (NULL == Min_stack) {
        printf("Min_stack is empty! \n");
        return ERROR;
    } else {
        *pt_value = Min_stack->value;
    }
    return OK;
}

int pust_nor(int value)
{

    st_stack *Nor_stack_tmp = NULL;
    Nor_stack_tmp = (st_stack*) malloc(sizeof (st_stack));
    if (NULL == Nor_stack_tmp) {
        printf("ERROR:malloc Nor_stack_tmp fail!\n");
        return ERROR;
    }

    Nor_stack_tmp->value = value;
    if (NULL == Nor_stack) {

        Nor_stack_tmp->next = NULL;
        Nor_stack = Nor_stack_tmp;
    } else {
        Nor_stack_tmp->next = Nor_stack;
        Nor_stack = Nor_stack_tmp;
    }

    return OK;
}

int pust_min(int value)
{
    int min_cur = 0;
    int ret = -1;
    st_stack *Min_stack_tmp = NULL;

    ret = getmin(&min_cur);
    if (ERROR == ret) {
        Min_stack_tmp = (st_stack*) malloc(sizeof (st_stack));
        if (NULL == Min_stack_tmp) {
            printf("ERROR:malloc Min_stack_tmp fail!\n");
            return ERROR;
        }

        Min_stack_tmp->value = value;
        Min_stack_tmp->next = NULL;
        Min_stack = Min_stack_tmp;
    } else {
        if (min_cur > value) {
            Min_stack_tmp = (st_stack*) malloc(sizeof (st_stack));
            if (NULL == Min_stack_tmp) {
                printf("ERROR:malloc Min_stack_tmp fail!\n");
                return ERROR;
            }
            Min_stack_tmp->value = value;
            Min_stack_tmp->next = Min_stack;
            Min_stack = Min_stack_tmp;
        }
    }

    return OK;
}

int pust(int value)
{
    int ret1 = ERROR;
    int ret2 = ERROR;
    ret1 = pust_nor(value);
    ret2 = pust_min(value);

    if (ERROR == ret1)
        return ERROR;
    if (ERROR == ret2)
        return ERROR;
    return OK;
}

int pop_min(int value_pop)
{
    int min_cur = 0;
    st_stack *Min_stack_tmp = NULL;
    int ret = ERROR;
    ret = getmin(&min_cur);
    if (ERROR == ret) {
        printf("ERROR:POP_MIN FAIL,Min_stack is empty!\n");
        return ERROR;
    } else {
        if (min_cur == value_pop) {
            Min_stack_tmp = Min_stack;
            Min_stack = Min_stack->next;
            free(Min_stack_tmp);
            return OK;
        }
    }

    return OK;
}

int pop_nor(int *pt_nor)
{

    st_stack *Nor_stack_tmp = NULL;

    if (NULL == Nor_stack) {
        printf("ERROR:POP_NOR FAIL,Nor_stack is empty!\n");
        return ERROR;
    }
    Nor_stack_tmp = Nor_stack;
    *pt_nor = Nor_stack->value;
    Nor_stack = Nor_stack->next;
    free(Nor_stack_tmp);

    return OK;
}

int pop(int *value)
{
    int pop_value_cur = 0;
    int ret1 = ERROR;
    int ret2 = ERROR;
    ret1 = pop_nor(&pop_value_cur);
    if (ERROR == ret1) {
        printf("ERROR:pop FAIL\n");
        return ERROR;
    }
    *value = pop_value_cur;
    ret2 = pop_min(pop_value_cur);
    if (ERROR == ret2) {
        printf("ERROR:pop FAIL\n");
        return ERROR;
    }
    return OK;
}

int stackinit(stack_handle *handle)
{
    if (NULL == handle) {
        printf("ERROR:stack_handle is NULL!\n");
        return ERROR;
    }
    *handle = (st_stack**) malloc(sizeof (st_stack*));
    if (NULL == *handle) {
        printf("ERROR:stack_handle malloc fail!\n");
        return ERROR;
    }
    **handle = NULL;
    return OK;
}

int stackfree(stack_handle *handle)
{
    //st_stack **pt_stack = NULL;
    st_stack *pt_stack_tmp = NULL;
    if (NULL == handle) {
        printf("ERROR:stack_handle is already NULL!\n");
        return ERROR;
    }

    if (*handle != NULL) {
        //pt_stack = *handle;
        while (**handle != NULL) {
            pt_stack_tmp = *(*handle);
            if (pt_stack_tmp->next != NULL) {
                *(*handle) = pt_stack_tmp->next;
            } else {
                *(*handle) = NULL;
            }
            free(pt_stack_tmp);
        }
        free(*handle);
        *handle = NULL;
    }
    return OK;
}

int pust_handle(stack_handle handle, int value)
{
    st_stack *stack_tmp = NULL;
    
    if (handle == NULL) {
        printf("ERROR: stack_handle is NULL,pust_handle do nothing!\n");
        return ERROR;
    }
    
    stack_tmp = (st_stack *) malloc(sizeof (st_stack));
    if (NULL == stack_tmp) {
        printf("ERROR:malloc stack fail!\n");
        return ERROR;
    }

    if (NULL == *handle) {
        *handle = stack_tmp;
        stack_tmp->next = NULL;
        stack_tmp->value = value;
    } else {
        stack_tmp->next = *handle;
        stack_tmp->value = value;
        *handle = stack_tmp;
    }
    return OK;
}

int pop_handle(stack_handle handle, int *value)
{
    st_stack *stack_tmp = NULL;
    if (handle == NULL) {
        printf("ERROR: stack_handle is NULL,pop_handle do nothing!\n");
        return ERROR;
    }

    if (NULL == *handle) {
        printf("ERROR:stack is empty!\n");
        return ERROR;
    }

    stack_tmp = *handle;
    *handle = stack_tmp->next;
    *value = stack_tmp->value;
    free(stack_tmp);
    stack_tmp = NULL;
    return OK;
}

int getvalue_handle(stack_handle handle, int *value)
{
    //st_stack *stack_tmp = NULL;
    if (handle == NULL) {
        printf("ERROR: stack_handle is NULL,getvalue_handle do nothing!\n");
        return ERROR;
    }

    if (NULL == *handle) {
        printf("ERROR:stack is empty!\n");
        return ERROR;
    }
    *value = (*handle)->value;
    return OK;
}
