
#include <stdio.h>

#include <iostream>
#include <memory>
#include <string>

#include "definitions.h"
#include "vector.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <curses.h>
#endif

class C_RenderSystem {
   private:
    Vector2D                    winSize = {-1, -1};

    WIN32_LINUX(HWND, WINDOW*)  pWindow = nullptr;

   public:
    void            init();
    void            clear();
    void            refresh();
    void            exit();

    void            printAt(std::string text, WIN32_LINUX(short, int) x, WIN32_LINUX(short, int) y);

    Vector2D        getSize() noexcept;
};

static std::unique_ptr<C_RenderSystem> g_pRenderSystem = std::make_unique<C_RenderSystem>();