#version 330 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 color;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 ourViewPos;
uniform Material ourMaterial;
uniform Light ourLight; 
uniform sampler2D ourTexture;

in vec3 inFragPos;  
in vec3 inNormal;
in vec2 inTexCoord;

out vec4 FragColor;

void main()
{
    // ambient
    vec3 ambient = ourLight.color * ourLight.ambient * ourMaterial.ambient;
  	
    // diffuse 
    vec3 norm = normalize(inNormal);
    vec3 lightDir = normalize(ourLight.position - inFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = ourLight.color * (diff * ourLight.diffuse * ourMaterial.diffuse);
    
    // specular
    vec3 viewDir = normalize(ourViewPos - inFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), ourMaterial.shininess);
    vec3 specular = ourLight.color * (spec * ourLight.specular * ourMaterial.specular);  
        
    vec3 result = ambient + diffuse + specular;
    vec4 texureColor = texture(ourTexture, inTexCoord);
    FragColor = vec4(result, 1.0) * texureColor;
}
