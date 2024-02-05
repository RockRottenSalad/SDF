#ifndef CAMERA_H
#define CAMERA_H

#include "giant-gml/giant-gml.h"

#define ONE_DEG M_PI/180.0

typedef struct
{
    vec3_t position;
    vec3_t direction;

    float speed;
} camera_t;

camera_t camera_init(vec3_t position);

void camera_move_forward(camera_t* camera, float dt);
void camera_move_back(camera_t* camera, float dt);
void camera_move_right(camera_t* camera, float dt);
void camera_move_left(camera_t* camera, float dt);

#endif
