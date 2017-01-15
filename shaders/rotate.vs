#version 130

in vec3 position;

out vec3 frag_color;

mat4 projection(
    float angle_of_view_y,
    float aspect_ratio,
    float z_near,
    float z_far
    ) {
    // from https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
    return mat4(
             vec4(1.0/(tan(angle_of_view_y)*aspect_ratio), 0.0, 0.0, 0.0),
             vec4(0.0, angle_of_view_y, 0.0, 0.0),
             vec4(0.0, 0.0, (z_far+z_near)/(z_far-z_near), -1.0),
             vec4(0.0, 0.0, (2.0*z_far*z_near)/(z_near-z_far), 0.0)
           );
}

mat4 rotate_x(float theta)
{
    return mat4(
        vec4(1.0, 0.0, 0.0, 0.0),
        vec4(0.0, cos(theta), sin(theta), 0.0),
        vec4(0.0, -sin(theta), cos(theta), 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );
}

void main() {
      gl_Position = projection(radians(45.0), 4.0/3.0, -0.1, -1000.0)
                    * rotate_x(radians(45.0))
                    * vec4(position, 1.0f);
      frag_color = vec3(1.0, 1.0, 1.0); // white
}