#ifndef STATE_H
#define STATE_H

#include "gfx/gfx.h"
#include "gfx/renderer.h"
#include "gfx/window.h"
#include "afx/buffer.h"
#include "util/util.h"

// holds the state associated with this instance of openGL
struct State {
    struct Window *window;
    struct Renderer renderer;
};

// global state
extern struct State state;

#endif