
#include "gfx/shader.h"

char* read_file(const char* file_path)
{
    FILE* fp = fopen(file_path, "r");
    assert(fp != NULL);

    char* string = (char*)0x0;
    long len = 0;
    size_t read = 0;

    (void)fseek(fp, 0L, SEEK_END);

    len = ftell(fp);
    assert(len > 0);
    string = malloc(len+1L);

    rewind(fp);
    read = fread(string, len, (size_t)1, fp);
    assert(read > 0);
    fclose(fp);

    string[len] = '\0';
    return string;
}

shader_t shader_init(const char* vert_shader_path, const char* frag_shader_path)
{
    shader_t new_shader = {0};

    unsigned int shader_program;
    unsigned int vert_shader, frag_shader;
    char* src = NULL;

    vert_shader = glCreateShader(GL_VERTEX_SHADER);
    src = read_file(vert_shader_path);
    glShaderSource(vert_shader, 1, (const char**)&src, NULL);
    glCompileShader(vert_shader);
    free(src);

    frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    src = read_file(frag_shader_path);
    glShaderSource(frag_shader, 1, (const char**)&src, NULL);
    glCompileShader(frag_shader);
    free(src);

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vert_shader);
    glAttachShader(shader_program, frag_shader);
    glLinkProgram(shader_program);

    int check;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &check);
    if(!check)
    {
        char buffer[512];
        glGetProgramInfoLog(shader_program, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(1);
    }
    new_shader.ptr = shader_program;

    new_shader.time_unf = glGetUniformLocation(new_shader.ptr, "a_time");
    new_shader.camera_position_unf = glGetUniformLocation(new_shader.ptr, "camera.position");
    new_shader.camera_direction_unf = glGetUniformLocation(new_shader.ptr, "camera.direction");
    new_shader.camera_mouse_unf = glGetUniformLocation(new_shader.ptr, "camera.mouse");

    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    return new_shader;
}

void shader_delete(shader_t shader_program)
{
    glDeleteProgram(shader_program.ptr);
}

void shader_set_uniform_float(unsigned int uniform, float value)
{
    glUniform1f(uniform, value);
}

void shader_set_uniform_vec2(unsigned int uniform, vec2_t value)
{
    glUniform2f(uniform, value[X], value[Y]);
}

void shader_set_uniform_vec3(unsigned int uniform, vec3_t value)
{
    glUniform3f(uniform, value[X], value[Y], value[Z]);
}
