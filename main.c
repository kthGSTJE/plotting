#include <stdio.h>

#define COMMAND_LENGTH 100

typedef struct GnuSettings
{
    char title[COMMAND_LENGTH];
    char xLabel[COMMAND_LENGTH];
    char yLabel[COMMAND_LENGTH];
    char plot[COMMAND_LENGTH];
} GnuSet;

int main(void) {
    GnuSet plotSettings = {
        .title = "set title \"Serious Head Injuries\"",
        .xLabel = "set xlabel \"Time\"",
        .yLabel = "set ylabel \"Force\"",
        .plot = "plot 'measurements.txt' with lines tit 'This is our graph'"
    };

    FILE *gnupipe = NULL;
    gnupipe = _popen("gnuplot -persistent", "w");

    //Execute gnucommands
    fprintf(gnupipe, "%s\n", plotSettings.title);
    fprintf(gnupipe, "%s\n", plotSettings.xLabel);
    fprintf(gnupipe, "%s\n", plotSettings.yLabel);
    fprintf(gnupipe, "%s\n", plotSettings.plot);

    return 0;
}