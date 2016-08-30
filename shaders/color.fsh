#version 400
in vec3 vertexColorFV;
out vec4 pixelColor;
void main()
{
	pixelColor= vec4(vertexColorFV,1);
}