#include <stdio.h>

#define COMMAND_LENGTH 100

typedef struct GnuCommands
{
    char title[COMMAND_LENGTH];
    char xLabel[COMMAND_LENGTH];
    char yLabel[COMMAND_LENGTH];
    char plot[COMMAND_LENGTH];
} Gnu;

int main(void) {
    Gnu gnuCommands = {
        .title = "set title \"Demo\"",
        .xLabel = "set xlabel \"Time\"",
        .yLabel = "set ylabel \"Force\"",
        .plot = "plot 'measurements.txt' with lines"
    };

    FILE *gnupipe = NULL;
    gnupipe = _popen("gnuplot -persistent", "w");

    //Execute gnucommands
    fprintf(gnupipe, "%s\n", gnuCommands.title);
    fprintf(gnupipe, "%s\n", gnuCommands.xLabel);
    fprintf(gnupipe, "%s\n", gnuCommands.yLabel);
    fprintf(gnupipe, "%s\n", gnuCommands.plot);

    return 0;
}