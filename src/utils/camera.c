
#include "utils/camera.h"
#include "giant-gml/vec2.h"
#include "giant-gml/vec3.h"

camera_t camera_init(vec3_t position)
{
    camera_t new_camera = {0};
    
    vec3_copy(position, &new_camera.position);
    vec3_copy((vec3_t){0.0, 0.0, 1.0}, &new_camera.direction);
    new_camera.speed = 0.01f;
    new_camera.sensitivity = 0.1;

    return new_camera;
}

void camera_move_forward(camera_t* camera, float dt)
{
    //

    vec3_t velocity;
    vec3_copy(camera->direction, &velocity);
    vec3_normalize(&velocity);
    vec3_scale(&velocity, camera->speed*dt);
    
    vec3_add(&camera->position, velocity);

}

void camera_move_back(camera_t* camera, float dt)
{
    //

    vec3_t velocity;
    vec3_copy(camera->direction, &velocity);
    vec3_normalize(&velocity);
    vec3_scale(&velocity, camera->speed*dt);
    
    vec3_sub(&camera->position, velocity);

}

void camera_move_right(camera_t* camera, float dt)
{
    vec3_t velocity, up = {0.0, 1.0, 0.0};
    vec3_cross_to(camera->direction, up, &velocity);
    vec3_normalize(&velocity);
    vec3_scale(&velocity, camera->speed*dt);
    
    vec3_sub(&camera->position, velocity);

}

void camera_move_left(camera_t* camera, float dt)
{
    vec3_t velocity, up = {0.0, 1.0, 0.0};
    vec3_cross_to(camera->direction, up, &velocity);
    vec3_normalize(&velocity);
    vec3_scale(&velocity, camera->speed*dt);
    
    vec3_add(&camera->position, velocity);

}

// 
void camera_mouse_move(camera_t* restrict camera, GLFWwindow* window)
{
    vec2_t mouse_pos = {0}, mouse_change = {0};

    double x, y;
    glfwGetCursorPos(window, &x, &y);

    mouse_pos[X] = (float)x;
    mouse_pos[Y] = (float)y;

    vec2_sub_to(mouse_pos, camera->prev_mouse, &mouse_change);
    vec2_scale(&mouse_change, camera->sensitivity);
    
    camera->yaw += mouse_change[X];
    camera->pitch -= mouse_change[Y];
    
    if(camera->pitch > 89.0f)
        camera->pitch = 89.0f;
    if(camera->pitch < -89.0f)
        camera->pitch = -89.0f;

    camera->direction[X] = cos(camera->yaw * DEG2RAD) * cos(camera->pitch * DEG2RAD);
    camera->direction[Y] = sin(camera->pitch * DEG2RAD);
    camera->direction[Z] = sin(camera->yaw * DEG2RAD) * cos(camera->pitch * DEG2RAD);
    vec3_normalize(&camera->direction);
//    vec3_print(camera->direction);

    vec2_copy(mouse_pos, &camera->prev_mouse);

}
