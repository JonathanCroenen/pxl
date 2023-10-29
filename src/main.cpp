#include "pxl.h"

class Test : public Pxl::Window {
public:
    Test(int width, int height, const char* title) : Pxl::Window(width, height, title) {
    }

    void OnStart() override {
        std::cout << "start" << std::endl;
    }

    void OnUpdate(float delta) override {
        for (int x = 0; x < _width; x++) {
            for (int y = 0; y < _height; y++) {
                auto color = (rand() % 255) / 255.0f;
                SetPixel(x, y, Pxl::Color(color));
            }
        }
    }
};

int main() {
    Test app = Test(800, 600, "title");
    app.Run();

    return 0;
}
