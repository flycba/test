/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: flycba
 *
 * Created on 2017年3月6日, 上午3:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * Simple C Test Suite
 */

void testPust_nor() {
    int value;
    int result = pust_nor(value);
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testPust_nor (newsimpletest) message=error message sample\n");
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testPust_nor (newsimpletest)\n");
    testPust_nor();
    printf("%%TEST_FINISHED%% time=0 testPust_nor (newsimpletest)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
