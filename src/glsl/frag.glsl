#version 440 core

in float time;
struct camera_t
{
    vec3 position;
    vec3 direction;
    vec2 mouse;
};

vec3 uv_direction;
vec3 ray_origin;
uniform camera_t camera;

mat4 look_at()
{
    // Cross product between up vector and forwards vector gives
    // us a vector that is perpendicular to both
    vec3 side = normalize(cross(camera.direction,vec3(0.0, 1.0, 0.0)));
    // up relative to camera
    vec3 up = normalize(cross(side, camera.direction));

    /*
    vec3 ww = normalize( camera.direction - camera.position );
    vec3 uu = ( cross(ww,vec3(sin(3.14/2),cos(3.14/2),0.0) ) );
    vec3 vv = ( cross(uu,ww));
    return mat3( uu, vv, ww );
    */
    

    return mat4(vec4(side, 0.0),
                vec4(up, 0.0),
                vec4(-camera.direction, 0.0),
                vec4(-dot(side, camera.position), -dot(up, camera.position), dot(camera.direction, camera.position), 1.0));
}

mat2 rotate_2d(float angle)
{
    return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}


// SDF stuff beyond this point
float sphere_sdf(vec3 position, vec3 center, float radius)
{
    return length(position - center) - radius;
}

float render()
{
    // time as in the variable "t" in an equation for a line e.g.: (x,y,z) = A + t*D
    float time = 0, dist = 0;
//    vec3 ray_position = camera.position; 
    vec3 ray_position = ray_origin; 

    vec3 sphere_pos = (vec4(0.0, 0.0, 0.0, 1.0)).xyz; 

    for(int n = 0; n < 50; n++)
    {
        dist = sphere_sdf(ray_position, vec3(sphere_pos), 1.0);

        if(dist < 0.01)
        {
            return time;
        }

        time += dist;
//        ray_position = camera.position + time * uv_direction;
        ray_position = ray_origin + time * uv_direction;
            
    }

    return -1.0;
}



out vec4 FragColor;

void main()
{
    vec2 uv = (2.0 * gl_FragCoord.xy - vec2(1920, 1080)) / min(1920, 1080);
    vec2 mouse = (2.0 * camera.mouse - vec2(1920, 1080)) / 1080*4.0;

//    uv_direction = normalize(vec3(uv.x, uv.y, 1.0)) * look_at();
//    vec4 uv_direction_tmp = look_at() * normalize(vec4(uv.x, uv.y, 1.0, 1.0));
//    vec4 uv_direction_tmp = normalize(vec4(uv.x, uv.y, 1.0, 1.0)) * look_at();


    float angle_rot = dot(vec3(camera.direction), vec3(0.0,0.0,1.0));


    uv_direction = vec3(uv.xy,1.0);
    ray_origin = camera.position;

    uv_direction.yz *= rotate_2d(mouse.y);

    uv_direction.xz *= rotate_2d(-mouse.x);

    float ray_march = render();

    vec3 color = vec3(0.2, 0.2, 0.4);

    if(ray_march >= 0.0)
    {
        color = vec3(1.0, 0.1, 0.1);
    }

    FragColor = vec4(color.xyz, 1.0);
}
