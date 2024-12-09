#include "gfx/window.h"
#include "gfx/gfx.h"

#include "state.h"

// global state
struct State state;

void init() {
    block_init();
    state.window = &window;
    renderer_init(&state.renderer);
    world_init(&state.world);
    ui_init(&state.ui);
    mouse_set_grabbed(true);

}

void destroy() {
    renderer_destroy(&state.renderer);
    world_destroy(&state.world);
    ui_destroy(&state.ui);
}

void tick() {
    state.ticks++;
    world_tick(&state.world);
    ui_tick(&state.ui);

}

void update() {
    renderer_update(&state.renderer);
    world_update(&state.world);
    ui_update(&state.ui);

    // wireframe toggle (T)
    if (state.window->keyboard.keys[GLFW_KEY_T].pressed) {
        state.renderer.flags.wireframe = !state.renderer.flags.wireframe;
    }

    // mouse toggle (ESC)
    if (state.window->keyboard.keys[GLFW_KEY_ESCAPE].pressed) {
        mouse_set_grabbed(!mouse_get_grabbed());
    }
}

void render() {
    renderer_prepare(&state.renderer, PASS_2D);
    renderer_push_camera(&state.renderer);
    ui_render(&state.ui);
    renderer_pop_camera(&state.renderer);
}


// main

int main(int argc, char *argv[]) {
    window_create(init, destroy, tick, update, render);
    window_loop();
}