#version 130

in vec3 frag_color;
in vec3 frag_pos;
in vec3 view_pos;
in vec3 Normal;
out vec4 out_color;

void main()
{
        // from https://learnopengl.com/#!Lighting/Basic-Lighting
        vec3 lightPos = vec3(0.0f, 0.0f, 0.0f);
        vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
        //Ambient
        float ambientStrength = 0.8f;
        vec3 ambient = ambientStrength * lightColor;
        //Diffuse

        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - frag_pos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        //specular
        float specularStrength = 0.2f;

        vec3 viewDir = normalize(view_pos - frag_pos);
        vec3 reflectDir = reflect(lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = specularStrength * spec * lightColor;

        vec3 result = ( specular + diffuse + ambient) * frag_color;
        out_color = vec4(result, 1.0f);
}
