#version 130

in vec3 frag_color;
in vec3 frag_pos;
in vec3 Normal;
out vec4 out_color;

void main()
{

        vec3 lightPos = vec3(0.0f,0.0f,3.0f);
        vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
        //Ambient
        float ambientStrength = 0.8f;
        vec3 ambient = ambientStrength * lightColor;
        //Diffuse

        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - frag_pos);
        float diff = max(dot(norm, lightPos), 0.0);
        vec3 diffuse = diff * lightColor;





        vec3 result = ( diffuse + ambient) * frag_color;
        out_color = vec4(result, 1.0f);
}
