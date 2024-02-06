#ifndef SHADER_H
#define SHADER_H

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#include "glad/glad.h"
#include "giant-gml/giant-gml.h"

typedef struct
{
    unsigned int ptr;

    unsigned int time_unf;
    unsigned int camera_position_unf, camera_direction_unf, camera_mouse_unf;
} shader_t;

// char pointer is malloc'ed
char* read_file(const char* file_path);
shader_t shader_init(const char* vert_shader_path, const char* frag_shader_path);
void shader_delete(shader_t shader_program);

void shader_set_uniform_float(unsigned int uniform, float value);
void shader_set_uniform_vec2(unsigned int uniform, vec2_t value);
void shader_set_uniform_vec3(unsigned int uniform, vec3_t value);

#endif
