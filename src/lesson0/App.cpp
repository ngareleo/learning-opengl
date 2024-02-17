#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int w, int h);
void processInput(GLFWwindow* window);

int main() 
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		// Above here we load the address of the OpenGL function pointers which are os-specific
		// GLFW gives us `glfwgetProcAddress` that defines the correct function based on which OS we're compiling for
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // This registers a callback to invoke every time the window size changes

	while (!glfwWindowShouldClose(window))  // This function checks if GLFW has been instructed to close
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		// glfwSwapBuffers will swap the color buffer that is used to render to during this render interation and show its output to the screen
		// It will swap the front and back buffers on every render looop
		// Color buffer is a large 2d buffer that contains color values for each pixel in GLFW's window
		// Front buffer is rendered and isn't changed
		// The back buffer is changed by rendering commands, then they are swapped


		glfwPollEvents(); 
		// glfwPollEvents Checks if any events are triggered like keyboard and mouse events, 
		// updates the window state and calls the corresponding functions which can be registered via callback functions


		processInput(window);
		// Check for inputs
	}

	glfwTerminate(); // Clean all of the GLFW resources that were allocated
	return 0;

}


void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	// The function takes GLFWwindow as its first argument and two integers indicating new window dims
	glViewport(0, 0, w, h);
}

void processInput(GLFWwindow* window)  
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}