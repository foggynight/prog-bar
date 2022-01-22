;;;; prog-bar.scm - prog-bar bindings for CHICKEN 5.
;;;; Copyright (C) 2022 Robert Coffey

(declare
  (foreign-declare "#define PROG_BAR_DEFINE")
  (foreign-declare "#include \"prog-bar.h\""))

(module prog-bar
    (make-prog-bar
     destroy-prog-bar
     prog-bar-done?
     prog-bar-step!
     prog-bar-draw
     with-prog-bar)
  (import scheme)
  (import (chicken base))
  (import (chicken foreign))
  (import bind)

  (bind "prog_bar_t *make_prog_bar(uint8_t, uint32_t);
         void destroy_prog_bar(prog_bar_t *);
         int prog_bar_done(prog_bar_t *);
         void prog_bar_step(prog_bar_t *);
         void prog_bar_draw(prog_bar_t *);")

  (define (make-prog-bar bar-size step-count)
    (make_prog_bar bar-size step-count))

  (define (destroy-prog-bar prog-bar)
    (destroy_prog_bar prog-bar))

  (define (prog-bar-done? prog-bar)
    (not (zero? (prog_bar_done prog-bar))))

  (define (prog-bar-step! prog-bar)
    (prog_bar_step prog-bar))

  (define (prog-bar-draw prog-bar)
    (prog_bar_draw prog-bar))

  (define-syntax with-prog-bar
    (syntax-rules ()
      ((with-prog-bar prog-bar bar-size step-count sexp ...)
       (let ((prog-bar (make-prog-bar bar-size step-count)))
         sexp ...
         (destroy-prog-bar prog-bar))))))
