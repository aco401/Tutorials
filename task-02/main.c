#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "led.h"

int echo(int argc, char **argv)
{
    printf("%s\n", *(argv + 1));

    (void)argc;
    (void)argv;

    return 0;
}

int toggle(int argc, char **argv)
{
    LED0_TOGGLE;

    (void)argc;
    (void)argv;

    return 0;
}

static const shell_command_t commands[] = {
    { "echo", "Prints text", echo },
    { "toggle", "Toggles the primary LED", toggle },
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("This is Task-02");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}