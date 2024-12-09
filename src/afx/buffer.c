#include "buffer.h"
#include "../state.h"
#include <AL/al.h>


Device = alcOpenDevice(NULL);

static void _init() {
    buffer.init();
}

static void _destroy() {
    buffer.destroy();
    glfwTerminate();
}