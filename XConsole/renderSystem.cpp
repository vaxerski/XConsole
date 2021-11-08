#include "renderSystem.h"

void C_RenderSystem::init() {
#ifdef _WIN32
    pWindow = GetConsoleWindow();
    RECT windowsize;
    GetWindowRect(pWindow, &windowsize);

    CONSOLE_SCREEN_BUFFER_INFO info = {0};
    GetConsoleScreenBufferInfo(GetStdHandle((DWORD)-11), &info);

    winSize.x = info.dwSize.X;
    winSize.y = info.dwSize.Y;
#else
    pWindow = initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    winSize.x = pWindow->_maxx + 1;
    winSize.y = pWindow->_maxy + 1;
#endif
}

void C_RenderSystem::refresh() {
#ifndef _WIN32
    wrefresh(pWindow);
#endif
}

void C_RenderSystem::clear() {
#ifdef _WIN32
    system("cls");
    SetConsoleCursorPosition(GetStdHandle((DWORD)-11), COORD{0, 0});
#else
    werase(pWindow);
    wmove(pWindow, 0, 0);
#endif
}

void C_RenderSystem::printAt(std::string text, WIN32_LINUX(short, int) x, WIN32_LINUX(short, int) y) {

    // checks the pos
    if (x > winSize.x || y > winSize.y || x < 0 || y < 0)
        return;
    // length clipping
    if (text.size() + x > winSize.x)
        text = text.substr(0, winSize.x - x);

#ifdef _WIN32
    SetConsoleCursorPosition(GetStdHandle((DWORD)-11), COORD{x, y});
    std::cout << text;
#else
    wmove(pWindow, y, x);
    wprintw(pWindow, text.c_str());
#endif
}

Vector2D C_RenderSystem::getSize() noexcept {
    return winSize;
}

void C_RenderSystem::exit() {
#ifndef _WIN32
    endwin();
#endif
}