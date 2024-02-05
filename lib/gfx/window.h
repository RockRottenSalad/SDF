#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include "utils/camera.h"
#include <GLFW/glfw3.h>
#include <assert.h>

#include "giant-gml/giant-gml.h"

typedef struct
{
    GLFWwindow* ptr;
    ivec2_t resolution;
    double delta_a, delta_b, delta_time;
    double fps;

    camera_t camera;
} window_t;

window_t window_init(const char* win_title, ivec2_t resolution, double fps);
void window_event(window_t* window);

#endif
