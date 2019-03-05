#ifndef _MEDIA_H
#define _MEDIA_H

#include <deque>
#include <SDL2/SDL.h>
#include <Cajita.hpp>
#include <Polygon/Polygon.hpp>
#include <Polygon/Triangle.hpp>

class World;

class Media {
public:
    enum class Key { a, b, r, q, Left, Right, Up, Down };
private:
    SDL_Window *mWin;
    int mWindowWidth, mWindowHeight;
    SDL_Renderer *mRenderer;

    SDL_Event mEvent;
    std::deque<Key> mKeyQueue;
    World& mWorld;
public:

    Media(World& w)
        : mWin{nullptr}, mWindowWidth{1280}, mWindowHeight{640},
          mRenderer{nullptr}, mWorld{w} {}
    void Init();
    void Close();
    void PollEvents();
    void Clear();
    void PresentScreen() {SDL_RenderPresent(mRenderer); }

    bool HasEvents() const { return !mKeyQueue.empty(); }

    Key PopKey() {
        Key res{mKeyQueue.front()};
        mKeyQueue.pop_front();
        return res;
    }

    World& GetWorld() { return mWorld; }
    
    void Draw(const Cajita& c) const;
    void Draw(const Polygon& p) const;
    void Draw(const SDL_Point* pts, int count) const;

    void DrawLines(const std::vector<Point<double>>& points) const;
    Point<int> GetWindowCenter() const {
        return Point<int> {mWindowWidth/2, mWindowHeight/2};
    }
};


#endif
