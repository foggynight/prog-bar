// prog-bar.h - ASCII progress bar library.
// Copyright (C) 2022 Robert Coffey

#ifndef PROG_BAR_H
#define PROG_BAR_H

#include <stdint.h>

// Types used to define progress bar sizes and counters respectively.
typedef uint8_t prog_bar_size_t;
typedef uint32_t prog_bar_step_t;

typedef struct prog_bar {
    prog_bar_size_t bar_size;   // bar size in cells
    prog_bar_step_t step_cnt;   // number of steps to take
    prog_bar_step_t step_cntr;  // number of steps taken
    float step_size;            // number of steps per cell
} prog_bar_t;

// Determine if a progress bar is done.
int prog_bar_done(prog_bar_t *pb);

// Have a progress bar take a step.
void prog_bar_step(prog_bar_t *pb);

// Draw a progress bar to stdout.
void prog_bar_draw(prog_bar_t *pb);

#endif // PROG_BAR_H

#ifdef PROG_BAR_DEFINE
#undef PROG_BAR_DEFINE

#include <stdio.h>
#include <stdlib.h>

void error(const char *msg) {
    puts(msg);
    exit(1);
}

prog_bar_t *make_prog_bar(prog_bar_size_t bar_size,
                          prog_bar_step_t step_count) {
    prog_bar_t *pb = malloc(sizeof(prog_bar_t));
    if (!pb) error("prog-bar: malloc failed");

    pb->bar_size = bar_size;
    pb->step_cnt = step_count;
    pb->step_cntr = 0;
    pb->step_size = (float)step_count / (float)bar_size;

    return pb;
}

void destroy_prog_bar(prog_bar_t *pb) {
    free(pb);
}

int prog_bar_done(prog_bar_t *pb) {
    return pb->step_cntr >= pb->step_cnt;
}

void prog_bar_step(prog_bar_t *pb) {
    ++pb->step_cntr;
}

void prog_bar_draw(prog_bar_t *pb) {
    prog_bar_size_t bar_end = 0;
    for (; bar_end < pb->bar_size; ++bar_end)
        if (bar_end * pb->step_size >= pb->step_cntr)
            break;

    putchar('[');
    for (prog_bar_size_t i = 0; i < pb->bar_size; ++i) {
        if (i < bar_end) putchar('#');
        else putchar('-');
    }
    putchar(']');
}

#endif // PROG_BAR_DEFINE
