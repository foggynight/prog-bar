#include <stdio.h>
#include <unistd.h>

#define PROG_BAR_DEFINE
#include "../prog-bar.h"

#define SLEEP_TIME (200 * 1000)

int main(void) {
    prog_bar_t *pb = make_prog_bar(8, 8);
    prog_bar_draw(pb);
    fflush(stdout);
    usleep(SLEEP_TIME);
    while (!prog_bar_done(pb)) {
        putchar('\r');
        prog_bar_step(pb);
        prog_bar_draw(pb);
        fflush(stdout);
        usleep(SLEEP_TIME);
    }
    putchar('\n');
    destroy_prog_bar(pb);
}
