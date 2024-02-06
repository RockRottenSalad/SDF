
#include "gfx/window.h"

window_t window_init(const char* win_title, ivec2_t resolution, double fps)
{
    window_t new_window = {0};

    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

    new_window.ptr = glfwCreateWindow(resolution[Y], resolution[X], win_title, NULL, NULL);
    assert(new_window.ptr != NULL);
    glfwMakeContextCurrent(new_window.ptr);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0,0,resolution[Y],resolution[X]);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    ivec2_copy(resolution, &new_window.resolution);
    new_window.delta_a = new_window.delta_b = new_window.delta_time = 0.0;
    new_window.fps = 1.0 / fps;

    new_window.camera = camera_init((vec3_t){0.0, 0.0, -3.0});

//    glfwSetCursorPosCallback(new_window.ptr, window_mouse_callback);
    glfwSetInputMode(new_window.ptr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    return new_window;
}

void window_event(window_t* restrict window)
{
    glfwPollEvents();

    if(glfwGetKey(window->ptr, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window->ptr, GLFW_TRUE);

    if(glfwGetKey(window->ptr, GLFW_KEY_W))
        camera_move_forward(&window->camera, window->delta_time);

    if(glfwGetKey(window->ptr, GLFW_KEY_S))
        camera_move_back(&window->camera, window->delta_time);

    if(glfwGetKey(window->ptr, GLFW_KEY_D))
        camera_move_right(&window->camera, window->delta_time);    

    if(glfwGetKey(window->ptr, GLFW_KEY_A))
        camera_move_left(&window->camera, window->delta_time);

}

