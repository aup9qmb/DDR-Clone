#ifndef STATE_H
#define STATE_H

#include "gfx/gfx.h"
#include "gfx/renderer.h"
#include "gfx/window.h"
#include "util/util.h"

struct State {
    struct Window *window;
    struct Renderer renderer;
};

// global state
extern struct State state;

#endif