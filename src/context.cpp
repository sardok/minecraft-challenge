#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <context.hpp>

Context::Context()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Minecraft", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Set the required callback functions
    //glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize OpenGL context");
    }

    // sf::ContextSettings settings;
    // settings.antialiasingLevel = 0;
    // settings.majorVersion = 4;
    // settings.minorVersion = 5;
    // settings.depthBits = 24;
    // settings.stencilBits = 8;
    // settings.attributeFlags = sf::ContextSettings::Attribute::Core;

    // auto vm = sf::VideoMode(1280, 720);
    // window.create(
    //     vm,
    //     "Minecraft",
    //     sf::Style::Close,
    //     settings);

    // glewExperimental = GL_TRUE;
    // if (glewInit() != GLEW_OK)
    //     throw std::runtime_error("Unable to init glew!");

    // glViewport(0, 0, 1280, 720);

    // window.setFramerateLimit(60);
}