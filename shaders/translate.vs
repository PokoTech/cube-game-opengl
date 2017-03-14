#version 130

in vec3 position;

out vec3 frag_color;

mat4 projection(
    float angle_of_view_y,
    float aspect_ratio,
    float z_near,
    float z_far
    ) {
    float f = 1.0/(tan(angle_of_view_y/2));
    // from https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
    return mat4(
             vec4(f/aspect_ratio, 0.0, 0.0, 0.0),
             vec4(0.0, f, 0.0, 0.0),
             vec4(0.0, 0.0, (z_far+z_near)/(z_near-z_far), -1.0),
             vec4(0.0, 0.0, (2.0*z_far*z_near)/(z_near-z_far), 0.0)
           );
}

mat4 translate(float x, float y, float z) {
    return mat4(
             vec4(1.0, 0.0, 0.0, 0.0),
             vec4(0.0, 1.0, 0.0, 0.0),
             vec4(0.0, 0.0, 1.0, 0.0),
             vec4(x, y, z, 1.0)
           );
}

void main() {
      gl_Position = projection(radians(90.0), 4.0/3.0, 0.1, 1000.0)
                      * translate(0.0, 0.0, -5.0)
                      * vec4(position, 1.0f);
      frag_color = vec3(1.0, 1.0, 1.0); // white
}