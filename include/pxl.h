#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

namespace Pxl {
    namespace {
        inline constexpr uint GL_TEXTURE_2D = 0x0DE1;
        inline constexpr uint GL_RGB = 0x1907;
        inline constexpr uint GL_FLOAT = 0x1406;
        inline constexpr uint GL_NEAREST = 0x2600;
        inline constexpr uint GL_TRIANGLES = 0x0004;
        inline constexpr uint GL_UNSIGNED_INT = 0x1405;
        inline constexpr uint GL_ARRAY_BUFFER = 0x8892;
        inline constexpr uint GL_ELEMENT_ARRAY_BUFFER = 0x8893;
        inline constexpr uint GL_STATIC_DRAW = 0x88E4;
        inline constexpr uint GL_VERTEX_SHADER = 0x8B31;
        inline constexpr uint GL_FRAGMENT_SHADER = 0x8B30;
        inline constexpr uint GL_LINK_STATUS = 0x8B82;
        inline constexpr uint GL_MAJOR_VERSION = 0x821B;
        inline constexpr uint GL_MINOR_VERSION = 0x821C;
        inline constexpr uint GL_VERSION = 0x1F02;
        inline constexpr uint GL_COMPILE_STATUS = 0x8B81;
        inline constexpr uint GL_INFO_LOG_LENGTH = 0x8B84;
        inline constexpr uint GL_TEXTURE_WRAP_S = 0x2802;
        inline constexpr uint GL_TEXTURE_WRAP_T = 0x2803;
        inline constexpr uint GL_FALSE = 0;
        inline constexpr uint GL_TRUE = 1;
        inline constexpr uint GL_REPEAT = 0x2901;
        inline constexpr uint GL_TEXTURE_MIN_FILTER = 0x2801;
        inline constexpr uint GL_TEXTURE_MAG_FILTER = 0x2800;

        typedef void (*GLDELETEVERTEXARRAYSPTR)(int n, const uint* arrays);
        typedef void (*GLDELETEBUFFERSPTR)(int n, const uint* buffers);
        typedef void (*GLDELETETEXTURESPTR)(int n, const uint* textures);
        typedef void (*GLDELETEPROGRAMPTR)(uint program);
        typedef void (*GLUSEPROGRAMPTR)(uint program);
        typedef void (*GLBINDVERTEXARRAYPTR)(uint array);
        typedef void (*GLBINDTEXTUREPTR)(uint target, uint texture);
        typedef void (*GLBINDBUFFERPTR)(uint target, uint buffer);
        typedef void (*GLDRAWELEMENTSPTR)(uint mode, int count, uint type,
                                          const void* indices);
        typedef void (*GLTEXIMAGE2DPTR)(uint target, int level, int internalformat,
                                        int width, int height, int border, uint format,
                                        uint type, const void* data);
        typedef void (*GLTEXPARAMETERIPTR)(uint target, uint pname, int param);
        typedef void (*GLSHADERSOURCEPTR)(uint shader, int count,
                                          const char* const* string, const int* length);
        typedef void (*GLCOMPILESHADERPTR)(uint shader);
        typedef void (*GLGETSHADERIVPTR)(uint shader, uint pname, int* params);
        typedef void (*GLGETSHADERINFOLOGPTR)(uint shader, int bufSize, int* length,
                                              char* infoLog);
        typedef uint (*GLCREATESHADERPTR)(uint type);
        typedef void (*GLATTACHSHADERPTR)(uint program, uint shader);
        typedef uint (*GLCREATEPROGRAMPTR)();
        typedef void (*GLLINKPROGRAMPTR)(uint program);
        typedef void (*GLGETPROGRAMIVPTR)(uint program, uint pname, int* params);
        typedef void (*GLGETPROGRAMINFOLOGPTR)(uint program, int bufSize, int* length,
                                               char* infoLog);
        typedef void (*GLDELETESHADERPTR)(uint shader);
        typedef void (*GLGENVERTEXARRAYSPTR)(int n, uint* arrays);
        typedef void (*GLGENBUFFERSPTR)(int n, uint* buffers);
        typedef void (*GLGENTEXTURESPTR)(int n, uint* textures);
        typedef void (*GLBUFFERDATAPTR)(uint target, int size, const void* data,
                                        uint usage);
        typedef void (*GLVERTEXATTRIBPOINTERPTR)(uint index, int size, uint type,
                                                 bool normalized, int stride,
                                                 const void* pointer);
        typedef void (*GLENABLEVERTEXATTRIBARRAYPTR)(uint index);
        typedef void (*GLVIEWPORTPTR)(int x, int y, int width, int height);
        typedef void (*GLGETINTEGERV)(uint pname, int* data);
        typedef const char* (*GLGETSTRINGPTR)(uint name);

        inline GLDELETEVERTEXARRAYSPTR glDeleteVertexArrays;
        inline GLDELETEBUFFERSPTR glDeleteBuffers;
        inline GLDELETETEXTURESPTR glDeleteTextures;
        inline GLDELETEPROGRAMPTR glDeleteProgram;
        inline GLUSEPROGRAMPTR glUseProgram;
        inline GLBINDVERTEXARRAYPTR glBindVertexArray;
        inline GLBINDTEXTUREPTR glBindTexture;
        inline GLBINDBUFFERPTR glBindBuffer;
        inline GLDRAWELEMENTSPTR glDrawElements;
        inline GLTEXIMAGE2DPTR glTexImage2D;
        inline GLTEXPARAMETERIPTR glTexParameteri;
        inline GLSHADERSOURCEPTR glShaderSource;
        inline GLCOMPILESHADERPTR glCompileShader;
        inline GLGETSHADERIVPTR glGetShaderiv;
        inline GLGETSHADERINFOLOGPTR glGetShaderInfoLog;
        inline GLCREATESHADERPTR glCreateShader;
        inline GLATTACHSHADERPTR glAttachShader;
        inline GLCREATEPROGRAMPTR glCreateProgram;
        inline GLLINKPROGRAMPTR glLinkProgram;
        inline GLGETPROGRAMIVPTR glGetProgramiv;
        inline GLGETPROGRAMINFOLOGPTR glGetProgramInfoLog;
        inline GLDELETESHADERPTR glDeleteShader;
        inline GLGENVERTEXARRAYSPTR glGenVertexArrays;
        inline GLGENBUFFERSPTR glGenBuffers;
        inline GLGENTEXTURESPTR glGenTextures;
        inline GLBUFFERDATAPTR glBufferData;
        inline GLVERTEXATTRIBPOINTERPTR glVertexAttribPointer;
        inline GLENABLEVERTEXATTRIBARRAYPTR glEnableVertexAttribArray;
        inline GLVIEWPORTPTR glViewport;
        inline GLGETINTEGERV glGetIntegerv;
        inline GLGETSTRINGPTR glGetString;

        inline int LoadGL() {
            glDeleteVertexArrays =
                (GLDELETEVERTEXARRAYSPTR)glfwGetProcAddress("glDeleteVertexArrays");
            glDeleteBuffers = (GLDELETEBUFFERSPTR)glfwGetProcAddress("glDeleteBuffers");
            glDeleteTextures =
                (GLDELETETEXTURESPTR)glfwGetProcAddress("glDeleteTextures");
            glDeleteProgram = (GLDELETEPROGRAMPTR)glfwGetProcAddress("glDeleteProgram");
            glUseProgram = (GLUSEPROGRAMPTR)glfwGetProcAddress("glUseProgram");
            glBindVertexArray =
                (GLBINDVERTEXARRAYPTR)glfwGetProcAddress("glBindVertexArray");
            glBindTexture = (GLBINDTEXTUREPTR)glfwGetProcAddress("glBindTexture");
            glBindBuffer = (GLBINDBUFFERPTR)glfwGetProcAddress("glBindBuffer");
            glDrawElements = (GLDRAWELEMENTSPTR)glfwGetProcAddress("glDrawElements");
            glTexImage2D = (GLTEXIMAGE2DPTR)glfwGetProcAddress("glTexImage2D");
            glTexParameteri = (GLTEXPARAMETERIPTR)glfwGetProcAddress("glTexParameteri");
            glShaderSource = (GLSHADERSOURCEPTR)glfwGetProcAddress("glShaderSource");
            glCompileShader = (GLCOMPILESHADERPTR)glfwGetProcAddress("glCompileShader");
            glGetShaderiv = (GLGETSHADERIVPTR)glfwGetProcAddress("glGetShaderiv");
            glGetShaderInfoLog =
                (GLGETSHADERINFOLOGPTR)glfwGetProcAddress("glGetShaderInfoLog");
            glCreateShader = (GLCREATESHADERPTR)glfwGetProcAddress("glCreateShader");
            glAttachShader = (GLATTACHSHADERPTR)glfwGetProcAddress("glAttachShader");
            glCreateProgram = (GLCREATEPROGRAMPTR)glfwGetProcAddress("glCreateProgram");
            glLinkProgram = (GLLINKPROGRAMPTR)glfwGetProcAddress("glLinkProgram");
            glGetProgramiv = (GLGETPROGRAMIVPTR)glfwGetProcAddress("glGetProgramiv");
            glGetProgramInfoLog =
                (GLGETPROGRAMINFOLOGPTR)glfwGetProcAddress("glGetProgramInfoLog");
            glDeleteShader = (GLDELETESHADERPTR)glfwGetProcAddress("glDeleteShader");
            glGenVertexArrays =
                (GLGENVERTEXARRAYSPTR)glfwGetProcAddress("glGenVertexArrays");
            glGenBuffers = (GLGENBUFFERSPTR)glfwGetProcAddress("glGenBuffers");
            glGenTextures = (GLGENTEXTURESPTR)glfwGetProcAddress("glGenTextures");
            glBufferData = (GLBUFFERDATAPTR)glfwGetProcAddress("glBufferData");
            glVertexAttribPointer =
                (GLVERTEXATTRIBPOINTERPTR)glfwGetProcAddress("glVertexAttribPointer");
            glEnableVertexAttribArray = (GLENABLEVERTEXATTRIBARRAYPTR)glfwGetProcAddress(
                "glEnableVertexAttribArray");
            glViewport = (GLVIEWPORTPTR)glfwGetProcAddress("glViewport");
            glGetIntegerv = (GLGETINTEGERV)glfwGetProcAddress("glGetIntegerv");
            glGetString = (GLGETSTRINGPTR)glfwGetProcAddress("glGetString");
            return 1;
        }
    } // namespace

    struct Color {
        float r, g, b;

        Color() : r(0), g(0), b(0) {}
        Color(float r, float g, float b) : r(r), g(g), b(b) {}
        Color(float x) : r(x), g(x), b(x) {}
    };

    class Window {
    public:
        int _width, _height;

        Window(int width, int height, const char* title, bool vsync = true);
        ~Window();

        void Run();
        inline Color GetPixel(uint32_t x, uint32_t y) const {
            return _pixels[y * _width + x];
        }
        inline void SetPixel(uint32_t x, uint32_t y, float r, float g, float b) {
            _pixels[y * _width + x].r = r;
            _pixels[3 * _width + x].g = g;
            _pixels[3 * _width + x].b = b;
        }
        inline void SetPixel(uint32_t x, uint32_t y, Color color) {
            _pixels[y * _width + x] = color;
        }

        virtual void OnStart() = 0;
        virtual void OnUpdate(float delta) = 0;

        virtual void KeyCallback(int key, int scancode, int action, int mods);
        virtual void MouseButtonCallback(int button, int action, int mods);
        virtual void CursorPositionCallback(double xpos, double ypos);
        virtual void ResizeCallback(int width, int height);

    private:
        void CreateContext(bool vsync);
        void CreateQuad();
        void CreateShaders();

        static void ErrorCallback(int32_t error, const char* description);
        void SetupCallbacks();

    private:
        GLFWwindow* _window;
        const char* _title;

        uint32_t _vao, _vbo, _ebo;
        uint32_t _texture;
        uint32_t _shader;

        std::vector<Color> _pixels;

        float _last_time;
    };

    inline Window::Window(int width, int height, const char* title, bool vsync)
        : _width(width), _height(height), _title(title) {

        _pixels = std::vector<Color>(width * height);

        CreateContext(vsync);
        SetupCallbacks();

        CreateShaders();
        CreateQuad();
    }

    inline Window::~Window() {
        glDeleteVertexArrays(1, &_vao);
        glDeleteBuffers(1, &_vbo);
        glDeleteBuffers(1, &_ebo);
        glDeleteTextures(1, &_texture);
        glDeleteProgram(_shader);

        glfwDestroyWindow(_window);
        glfwTerminate();
    }

    inline void Window::Run() {
        glfwShowWindow(_window);

        _last_time = glfwGetTime();

        glUseProgram(_shader);
        glBindVertexArray(_vao);
        glBindTexture(GL_TEXTURE_2D, _texture);

        OnStart();

        while (!glfwWindowShouldClose(_window)) {
            glfwPollEvents();

            float current_time = glfwGetTime();
            OnUpdate(current_time - _last_time);
            _last_time = current_time;

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_FLOAT,
                         _pixels.data());
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(_window);
        }
    }

    inline void Window::KeyCallback(int key, int, int action, int) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(_window, GLFW_TRUE);
        }
    }

    inline void Window::MouseButtonCallback(int, int, int) {}

    inline void Window::CursorPositionCallback(double, double) {}

    inline void Window::ResizeCallback(int, int) {}

    inline void Window::CreateContext(bool vsync) {
        glfwSetErrorCallback(Window::ErrorCallback);

        if (!glfwInit()) {
            std::cerr << "failed to initialize glfw" << std::endl;
            // throw std::runtime_error("failed to initialize glfw");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        _window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

        if (!_window) {
            glfwTerminate();
            throw std::runtime_error("failed to create glfw window");
        }

        glfwMakeContextCurrent(_window);
        glfwSwapInterval((int)vsync);

        if (!LoadGL()) {
            throw std::runtime_error("failed to load opengl function pointers");
        }

        int32_t frame_width, frame_height;
        glfwGetFramebufferSize(_window, &frame_width, &frame_height);
        glViewport(0, 0, frame_width, frame_height);

        int32_t version_major, version_minor;
        glGetIntegerv(GL_MAJOR_VERSION, &version_major);
        glGetIntegerv(GL_MINOR_VERSION, &version_minor);

        if (version_major != 4 || version_minor != 6) {
            throw std::runtime_error("failed to create an opengl 4.6 context");
        }

        std::cout << "opengl version: " << glGetString(GL_VERSION) << std::endl;
    }

    inline void Window::SetupCallbacks() {
        glfwSetWindowUserPointer(_window, this);

        glfwSetKeyCallback(
            _window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
                Window* app = (Window*)glfwGetWindowUserPointer(window);
                app->KeyCallback(key, scancode, action, mods);
            });

        glfwSetMouseButtonCallback(
            _window, [](GLFWwindow* window, int button, int action, int mods) {
                Window* app = (Window*)glfwGetWindowUserPointer(window);
                app->MouseButtonCallback(button, action, mods);
            });

        glfwSetCursorPosCallback(_window,
                                 [](GLFWwindow* window, double xpos, double ypos) {
            Window* app = (Window*)glfwGetWindowUserPointer(window);
            app->CursorPositionCallback(xpos, ypos);
        });

        glfwSetFramebufferSizeCallback(_window,
                                       [](GLFWwindow* window, int width, int height) {
            Window* app = (Window*)glfwGetWindowUserPointer(window);

            app->_width = width;
            app->_height = height;
            glViewport(0, 0, width, height);

            app->_pixels.resize(width * height);

            app->ResizeCallback(width, height);
        });
    }

    inline void Window::CreateQuad() {
        // clang-format off
        float vertices[] = {
            -1.0f, -1.0f, 0.0f, 1.0f, // bottom left
             1.0f, -1.0f, 1.0f, 1.0f, // bottom right
             1.0f,  1.0f, 1.0f, 0.0f, // top right
            -1.0f,  1.0f, 0.0f, 0.0f, // top left
        };
        // clang-format on

        uint32_t indices[] = {0, 1, 2, 2, 3, 0};

        glGenVertexArrays(1, &_vao);
        glGenBuffers(1, &_vbo);
        glGenBuffers(1, &_ebo);

        // bind vao
        glBindVertexArray(_vao);

        // bind vbo
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // bind ebo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // vertex attribute pos
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // vertex attribute tex coords
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                              (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // unbind
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // create texture
        glGenTextures(1, &_texture);
        glBindTexture(GL_TEXTURE_2D, _texture);

        // set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // upload texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_FLOAT,
                     _pixels.data());

        // unbind
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    namespace {
        inline const char* vertex_shader_source = R"(
        #version 460 core

        layout (location = 0) in vec2 a_pos;
        layout (location = 1) in vec2 a_tex_coords;

        out vec2 tex_coords;

        void main() {
        gl_Position = vec4(a_pos, 0.0, 1.0);
        tex_coords = a_tex_coords;
        }
    )";

        inline const char* fragment_shader_source = R"(
        #version 460 core

        in vec2 tex_coords;

        out vec4 color;

        uniform sampler2D tex;

        void main() {
        color = texture(tex, tex_coords);
        }
    )";
    } // namespace

    inline void Window::CreateShaders() {
        uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glCompileShader(vertex_shader);

        int32_t success;
        char info_log[512];
        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
            std::cerr << "vertex shader compilation failed\n" << info_log << std::endl;
            return;
        }

        uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
        glCompileShader(fragment_shader);

        glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
            std::cerr << "fragment shader compilation failed\n" << info_log << std::endl;
            return;
        }

        _shader = glCreateProgram();
        glAttachShader(_shader, vertex_shader);
        glAttachShader(_shader, fragment_shader);
        glLinkProgram(_shader);

        glGetProgramiv(_shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(_shader, 512, NULL, info_log);
            std::cerr << "shader program linking failed\n" << info_log << std::endl;
            return;
        }

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    inline void Window::ErrorCallback(int32_t error, const char* description) {
        std::cerr << "glfw error (" << error << "): " << description << std::endl;
    }
} // namespace Pxl
