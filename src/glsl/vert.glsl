#version 440 core

layout (location = 0) in vec2 pos;

uniform float a_time;
out float time;

void main()
{
    time = a_time;
    gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);
}
