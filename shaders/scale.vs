#version 130

in vec3 position;
in vec4 camera;

out vec3 frag_color;

mat4 projection(
    float angle_of_view,
    float aspect_ratio,
    float z_near,
    float z_far
    ) {
    return mat4(
             vec4(1.0/tan(angle_of_view), 0.0, 0.0, 0.0),
             vec4(0.0, aspect_ratio/tan(angle_of_view), 0.0, 0.0),
             vec4(0.0, 0.0, (z_far+z_near)/(z_far-z_near), 1.0),
             vec4(0.0, 0.0, -2.0*z_far*z_near/(z_far-z_near), 0.0)
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
      gl_Position = projection(radians(45.0), 4.0/3.0, -0.1, -1000.0)
                    * camera
                    * translate(2.0, 2.0, -10.0)
                    * vec4(position, 1.0f);
      frag_color = vec3(1.0, 1.0, 1.0); // white
}