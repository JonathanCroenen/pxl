#include "pxl.h"

#include <vector>


struct Color {
    float r, g, b;
};


class Test : public Pxl::Window {
public:
    Test(int width, int height, const char* title) : Pxl::Window(width, height, title) {
        pixels.resize(_width * _height);
    }

    void OnStart() override {
        std::cout << "start" << std::endl;
    }

    void OnUpdate(float delta) override {
        static float time = 0.0f;
        time += delta;
        if (time > 2.0f) {
            std::cout << "Frametime: " << delta << std::endl;
            time = 0.0f;
        }
 
        for (int x = 0; x < _width; x++) {
            for (int y = 0; y < _height; y++) {
                auto color = (rand() % 255) / 255.0f;
                pixels[x + y * _width].r = color;
                pixels[x + y * _width].g = color;
                pixels[x + y * _width].b = color;
            }
        }

        Blit(&pixels[0].r, _width, _height);
    }

    std::vector<Color> pixels;
};

int main() {
    Test app = Test(800, 600, "title");
    app.Run();

    return 0;
}
