#include <gpio/gpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifdef __arm__
#include <bsp/bsp.h>
#endif

#define GPIO_PIN_NUM_IN1 12U
#define GPIO_PIN_NUM_IN2 13U
#define GPIO_PIN_NUM_ENA 6U
#define GPIO_PIN_NUM_IN4 20U
#define GPIO_PIN_NUM_IN3 21U
#define GPIO_PIN_NUM_ENB 26U
#define DELAY_S 2

#define HIGH 1
#define LOW 0

void back(GpioHandle* handle){
    fprintf(stderr, "Ahead\n");
     GpioOut(*handle, GPIO_PIN_NUM_IN1, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_IN2, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN3, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_IN4, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_ENA, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_ENB, HIGH);
}

void stop(GpioHandle* handle) {
    GpioOut(*handle, GPIO_PIN_NUM_IN1, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN2, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN3, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN4, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_ENA, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_ENB, LOW);
}

void forward(GpioHandle* handle) {
    fprintf(stderr, "Aback\n");
    GpioOut(*handle, GPIO_PIN_NUM_IN1, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN2, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_IN3, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN4, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_ENA, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_ENB, HIGH);

}

void right(GpioHandle* handle) {
     fprintf(stderr, "Right\n");
    GpioOut(*handle, GPIO_PIN_NUM_IN1, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_IN2, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN3, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN4, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_ENA, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_ENB, HIGH);
}

void left(GpioHandle* handle) {
    fprintf(stderr, "Left\n");
    GpioOut(*handle, GPIO_PIN_NUM_IN1, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN2, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_IN3, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_IN4, LOW);
    GpioOut(*handle, GPIO_PIN_NUM_ENA, HIGH);
    GpioOut(*handle, GPIO_PIN_NUM_ENB, HIGH);
}

void trajectory(GpioHandle* handle) {
  
}

int main(int argc, const char *argv[])
{
    fprintf(stderr, "GPIO_output test began\n");

    if (GpioInit())
    {
        fprintf(stderr, "Init of GPIO failed\n");
        return EXIT_FAILURE;
    }

    /* initialize and setup gpio0 port */
    GpioHandle handle = NULL;
    if (GpioOpenPort("GPIO0", &handle) || handle == GPIO_INVALID_HANDLE)
    {
        fprintf(stderr, "Open port of GPIO failed\n");
        return EXIT_FAILURE;
    }

    GpioSetMode(handle, GPIO_PIN_NUM_IN1, GPIO_DIR_OUT);
    GpioSetMode(handle, GPIO_PIN_NUM_IN2, GPIO_DIR_OUT);
    GpioSetMode(handle, GPIO_PIN_NUM_IN3, GPIO_DIR_OUT);
    GpioSetMode(handle, GPIO_PIN_NUM_IN4, GPIO_DIR_OUT);
    GpioSetMode(handle, GPIO_PIN_NUM_ENA, GPIO_DIR_OUT);
    GpioSetMode(handle, GPIO_PIN_NUM_ENB, GPIO_DIR_OUT);


    forward(handle);
    sleep(3);
    usleep(300000);
    right(handle);
    usleep(500000);
    forward(handle);
    sleep(1);
    right(handle);
    usleep(550000);
    forward(handle);
    sleep(3);
    usleep(300000);
    right(handle);
    usleep(500000);
    forward(handle);
    sleep(1);

    stop(p_handle);
    if(GpioClosePort(handle))
    {
        fprintf(stderr, "Close port of GPIO failed\n");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "Finish of the test.\n");

    return EXIT_SUCCESS;
}
