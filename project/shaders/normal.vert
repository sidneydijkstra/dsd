#version 330 core
layout (location = 0) in vec3 vertPosition;
layout (location = 1) in vec3 vertNormal;
layout (location = 2) in vec2 vertTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 inFragPos;
out vec3 inNormal;
out vec2 inTexCoord;

void main()
{
    inFragPos = vec3(model * vec4(vertPosition, 1.0));
    inNormal = vertNormal;
    inTexCoord = vertTexCoord;

    // set position
    gl_Position = projection * view * vec4(inFragPos, 1.0f);
}
