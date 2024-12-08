
#if defined(_MSC_VER)
 // Make MS math.h define M_PI
 #define _USE_MATH_DEFINES
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


GLfloat alpha = 210.f, beta = -70.f;
GLfloat zoom = 2.f;

double cursorX;
double cursorY;

struct Vertex
{
    GLfloat x, y, z;
    GLfloat r, g, b;
};

#define GRIDW 50
#define GRIDH 50
#define VERTEXNUM (GRIDW*GRIDH)

#define QUADW (GRIDW - 1)
#define QUADH (GRIDH - 1)
#define QUADNUM (QUADW*QUADH)

GLuint quad[4 * QUADNUM];
struct Vertex vertex[VERTEXNUM];


double dt;
double p[GRIDW][GRIDH];
double vx[GRIDW][GRIDH], vy[GRIDW][GRIDH];
double ax[GRIDW][GRIDH], ay[GRIDW][GRIDH];


//========================================================================
// Draw scene
//========================================================================

void draw_scene(GLFWwindow* window)
{
    // Clear the color and depth buffers
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // We don't want to modify the projection matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Move back
    glTranslatef(0.0, 0.0, -zoom);
    // Rotate the view
    glRotatef(beta, 1.0, 0.0, 0.0);
    glRotatef(alpha, 0.0, 0.0, 1.0);

    glDrawElements(GL_QUADS, 4 * QUADNUM, GL_UNSIGNED_INT, quad);

    glfwSwapBuffers(window);
}


//=======================================
// Initialize Miscellaneous OpenGL state
//=======================================

void init_opengl(void)
{

    // Use Gouraud (smooth) shading
    glShadeModel(GL_SMOOTH);

    // Switch on the z-buffer
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(struct Vertex), vertex);
    glColorPointer(3, GL_FLOAT, sizeof(struct Vertex), &vertex[0].r); // Pointer to the first color

    glPointSize(2.0);

    // Background color is black
    glClearColor(0, 0, 0, 0);
}


//=======================================
// Print errors
//=======================================

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


//=======================================
// Handle key strokes
//=======================================

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;

    switch (key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        case GLFW_KEY_LEFT:
            alpha += 5;
            break;
        case GLFW_KEY_RIGHT:
            alpha -= 5;
            break;
        case GLFW_KEY_UP:
            beta -= 5;
            break;
        case GLFW_KEY_DOWN:
            beta += 5;
            break;
        case GLFW_KEY_PAGE_UP:
            zoom -= 0.25f;
            if (zoom < 0.f)
                zoom = 0.f;
            break;
        case GLFW_KEY_PAGE_DOWN:
            zoom += 0.25f;
            break;
        default:
            break;
    }
}


//=======================================
// Callback function for mouse button events
//=======================================

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;

    if (action == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwGetCursorPos(window, &cursorX, &cursorY);
    }
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}


//=======================================
// Callback function for cursor motion events
//=======================================

void cursor_position_callback(GLFWwindow* window, double x, double y)
{
    if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
    {
        alpha += (GLfloat) (x - cursorX) / 10.f;
        beta += (GLfloat) (y - cursorY) / 10.f;

        cursorX = x;
        cursorY = y;
    }
}


//=======================================
// Callback function for scroll events
//=======================================

void scroll_callback(GLFWwindow* window, double x, double y)
{
    zoom += (float) y / 4.f;
    if (zoom < 0)
        zoom = 0;
}


//=======================================
// Callback function for framebuffer resize events
//=======================================

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    float ratio = 1.f;

    if (height > 0)
        ratio = (float) width / (float) height;

}


//=======================================
// main
//=======================================

int main(int argc, char* argv[])
{
    GLFWwindow* window;
    int width, height;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "DDR-Clone", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // glfw set keybinds
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // glfw: set state context to window
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);


    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    // initialize OpenGL
    init_opengl();

    while (!glfwWindowShouldClose(window))
    {
        // Draw to OpenGL display
        draw_scene(window);

        glfwPollEvents();
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}