#version 440 core

in float time;
struct camera_t
{
    vec3 position;
    vec3 direction;
};

vec3 uv_direction;
uniform camera_t camera;

float sphere_sdf(vec3 position, vec3 center, float radius)
{
    return length(position - center) - radius;
}

float render()
{
    // time as in the variable "t" in an equation for a line e.g.: (x,y,z) = A + t*D
    float time = 0, dist = 0;
    vec3 ray_position = camera.position; 

    for(int n = 0; n < 50; n++)
    {
        dist = sphere_sdf(ray_position, vec3(0.0,0.0,3.0), 1.0);

        if(dist < 0.01)
        {
            return time;
        }

        time += dist;
        ray_position = camera.position + time * uv_direction;
            
    }

    return -1.0;
}

mat3 rotate_y(float angle)
{
    mat3 rotation_matrix;
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);

    rotation_matrix[0][0] = cos_angle;
    rotation_matrix[0][1] = 0;
    rotation_matrix[0][2] = sin_angle;

    rotation_matrix[1][0] = 0;
    rotation_matrix[1][1] = 1;
    rotation_matrix[1][2] = 0;

    rotation_matrix[2][0] = -sin_angle;
    rotation_matrix[2][1] = 0;
    rotation_matrix[2][2] = cos_angle;

    return rotation_matrix;
}

out vec4 FragColor;

void main()
{
    vec2 uv = (2.0 * gl_FragCoord.xy - vec2(1920, 1080)) / min(1920, 1080);

//    camera.position = vec3(0.0, 0.0, 3.0);
    uv_direction = normalize(vec3(uv.x, uv.y, 1.0));

//    mat3 mat = rotate_y(cos(time)*3.1);
 //   camera.direction = mat * camera.direction;
    


    float ray_march = render();

    vec3 color = vec3(0.2, 0.2, 0.4);

    if(ray_march >= 0.0)
    {
        color = vec3(1.0, 0.1, 0.1);
    }

    FragColor = vec4(color.xyz, 1.0);
}
