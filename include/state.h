#pragma once
#include <GLFW/glfw3.h>

struct State
{
	int width, height;
	const char* title;
	GLFWwindow* window;

	State(int width, int height, const char* title);
};

extern State state;