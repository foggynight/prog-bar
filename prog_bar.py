# prog_bar.py - prog-bar ported to Python.
# Copyright (C) 2022 Robert Coffey
# Released under the MIT license.

class ProgBar:
    __slots__ = ('bar_size', 'step_count', 'step_counter', 'step_size')

    def __init__(self, bar_size, step_count):
        self.bar_size = bar_size
        self.step_count = step_count
        self.step_counter = 0
        self.step_size = step_count / bar_size

    def done(self):
        return self.step_counter >= self.step_count

    def step(self):
        self.step_counter += 1

    def draw(self):
        bar_end = 0
        while bar_end < self.bar_size:
            if bar_end * self.step_size >= self.step_counter:
                break
            bar_end += 1
        print(f"[{'#'*bar_end}{'-'*(self.bar_size-bar_end)}]", end='')
