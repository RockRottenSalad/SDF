
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "gfx/window.h"
#include "gfx/shader.h"

#define FPS_60 60.0

unsigned int vao, vbo;

// Setup VAO and VBO with a square that covers the whole screen
// Since ray marching is being used, all drawing is done via the fragment shader and
// not polygons defined in the VBO
void buffer_setup(unsigned int*,unsigned int*);
void buffer_cleanup(unsigned int*,unsigned int*);

int main(void)
{

    window_t window = window_init("SDF test", (ivec2_t){1080, 1920}, FPS_60);
    shader_t shader = shader_init("./src/glsl/vert.glsl", "./src/glsl/frag.glsl");
    buffer_setup(&vao, &vbo);
    glUseProgram(shader.ptr);

    GLenum err = 0;
    while(!glfwWindowShouldClose(window.ptr))
    {
        window.delta_b = glfwGetTime();
        window.delta_time = window.delta_b - window.delta_a;
        window_event(&window);

        err = glGetError();
        if(err != GL_NO_ERROR)
            printf("ERROR CODE: %d\n", err);

        if(window.delta_time >= window.fps)
        {
            camera_mouse_move(&window.camera, window.ptr);
            shader_set_uniform_float(shader.time_unf, (float)glfwGetTime());
            shader_set_uniform_vec3(shader.camera_position_unf, window.camera.position);
            shader_set_uniform_vec3(shader.camera_direction_unf, window.camera.direction);
            shader_set_uniform_vec2(shader.camera_mouse_unf, window.camera.prev_mouse);

            glDrawArrays(GL_TRIANGLES, 0, 6);

            glfwSwapBuffers(window.ptr);

            window.delta_a = window.delta_b;
        }
    }

    glfwDestroyWindow(window.ptr);
    glfwTerminate();
    buffer_cleanup(&vao, &vbo);

    return 0;
}


void buffer_setup(unsigned int *vao, unsigned int *vbo)
{
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);

    float box[] = { -1.0f, -1.0f,
                     1.0f, -1.0f,
                     1.0f,  1.0f,

                     1.0f,  1.0f,
                    -1.0f,  1.0f,
                    -1.0f, -1.0f };

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12, box, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    
}

void buffer_cleanup(unsigned int *vao, unsigned int *vbo)
{
    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(1, vbo);
}
