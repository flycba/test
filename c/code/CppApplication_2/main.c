#include <stdio.h>  
#include <linux/input.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <pthread.h>
#include <unistd.h>
#include <termios.h>

#define DEV_PATH "/dev/input/event3"   //difference is possible 

void *key_test() {
    int keys_fd;
    int n = 0;
    struct input_event t;
    keys_fd = open(DEV_PATH, O_RDONLY);
    if (keys_fd <= 0) {
        printf("open /dev/input/event3 device error!\n");
        return -1;
    }
    while (1) {
        if (read(keys_fd, &t, sizeof (t)) == sizeof (t)) {
            if (t.type == EV_KEY)
                if (t.value == 0 || t.value == 1) {
                    printf("Key %d %s\n", (int) (t.code), (t.value) ? "Pressed" : "Released");
                    if (t.code == KEY_ESC)
                        break;
                }
        } else {
            printf("else\n");
        }
    }
    close(keys_fd);
}

void *printfhello(void *hello) {
    int loop_num = 0;
    while (1) {
        loop_num++;
        sleep(1);
        printf("[%02d] ni hao = %s\n", loop_num, (char *) hello);
        if (loop_num >= 10)break;
    }
}

int main() {
    
    int err = -1;
    int err1 = -1;
    pthread_t threads;
    pthread_t threads1;
    char *hello = "hello world!";

    err = pthread_create(&threads, NULL, key_test, NULL);

    if (err != 0) {
        char * mesg = strerror(err);
        printf("Can't create thread :[%s]", mesg);
    }

    err1 = pthread_create(&threads1, NULL, printfhello, (void *) hello);

    if (err1 != 0) {
        char * mesg1 = strerror(err1);
        printf("Can't create thread :[%s]", mesg1);
    }

    printf("read1\n");
    while (1);
    return 0;
}
