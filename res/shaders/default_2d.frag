#version 330 core

out vec4 frag_colour;
in vec2 frag_coord;

uniform sampler2D u_texture;
uniform float u_sample = 0.0;

void main()
{
	frag_colour = vec4(texture(u_texture, frag_coord).rgb, max(0.001, 1.0 / (1.0 + u_sample)));
}
