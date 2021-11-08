#include "XConsole/include.h"
#include <thread>

// Basic example main, prints out hello world scrolling through the screen.

int main(int argc, char** argv) {

    g_pRenderSystem->init();

    int x = 0;

    while(1) {
        x++;
        if(x > g_pRenderSystem->getSize().x - ((std::string)("Hello World!")).size())
            x = 0;

        g_pRenderSystem->clear();

        g_pRenderSystem->printAt("Hello World!", x, 5);

        g_pRenderSystem->refresh();

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }

    g_pRenderSystem->exit();
    return 1;
}