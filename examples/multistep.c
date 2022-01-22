#include <stdio.h>
#include <unistd.h>

#define PROG_BAR_DEFINE
#include "../prog-bar.h"

#define SLEEP_TIME (200 * 1000)

int main(void) {
    prog_bar_t *pb = make_prog_bar(5, 8);
    prog_bar_draw(pb);
    putchar('\n');
    usleep(SLEEP_TIME);
    while (!prog_bar_done(pb)) {
        prog_bar_step(pb);
        prog_bar_draw(pb);
        putchar('\n');
        usleep(SLEEP_TIME);
    }
    destroy_prog_bar(pb);
}
