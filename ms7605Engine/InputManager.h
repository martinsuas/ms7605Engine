/*
Partial credits to this code:
http://learnopengl.com/#!Getting-started/Camera
*/
#pragma once
#include <GL/glew.h>
// Great for small program; makes programs more portable, handles windows
// creation and management, keyboard and mouse input, and a "game loop"
// GL_TRUE is 1 if it works, false 0 if it fails.
#include <GLFW/glfw3.h>
// Math library based on OpenGL Shading Language, making it easier to give values to
// shader variables and to buffer/upload data. Just library, hence .hpp
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <FreeImage.h>
#include <map>
#include "FreeCamera.h"


/*
*/
class InputManager {
public:
	InputManager();
	~InputManager();

	static void mouseClick(GLFWwindow * windowPtr, int button,
		int action, int mods);

	static void keyCallback(GLFWwindow * windowPtr, int key,
		int scancode, int action, int mods);

	static void mouseCallback(GLFWwindow * windowPtr, double xpos, double ypos);

	static void scrollCallback(GLFWwindow * window, double xoff, double yoff);


	static void init(GLFWwindow* windowPtr, int width, int height, FreeCamera &cam);

	static bool press(int key);

private:
	static std::map<int, bool> keyDown;
	static bool firstMouse;
	static GLfloat lastX, lastY;
	static FreeCamera* cam;
};