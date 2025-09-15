#include "state.h"

State::State(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW." << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->width = width;
	this->height = height;
	this->title = title;

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Could not initialize GLFW window." << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Could not initialize GLAD." << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}