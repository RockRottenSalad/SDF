
#include "utils/camera.h"

camera_t camera_init(vec3_t position)
{
    camera_t new_camera = {0};
    
    vec3_copy(position, &new_camera.position);
    vec3_copy((vec3_t){0.0, 0.0, 1.0}, &new_camera.direction);
    new_camera.speed = 0.001f;

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
