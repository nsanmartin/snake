#ifndef _WORLD_H
#define _WORLD_H


#include <chrono>
#include <vector>

#include <Media.hpp>
#include <Board.hpp>
#include <RectBox.hpp>
#include <Plane.hpp>
#include <Polygon/Polygon.hpp>
#include <State/WorldState.hpp>

class World {
public:
    enum class StateEnum { Presentation = 0, Move };
private:
    bool mContinue;
    Media mMedia;

    Board mBoard;
    Point<int> mBlockPos;
    Point<double> mNormal; // to proyect
    Plane mPlane;
    RectBox mBox;
    Point<int> mBoxDirection;
    
    std::chrono::steady_clock::time_point mLastBoxFall;
    double mFallTimeMilli;
    //todo: use unique ptrs
    std::vector<Polygon*> mPolygons;

    size_t mActivePolygon;
    //todo: use unique ptrs
    std::vector<WorldState*> mStates;
    StateEnum mPresentState;
public:
    
    World();
    ~World();
    void Loop();
    void Update();
    void Quit() { mContinue = false; }
    WorldState* GetState() {
        return mStates.at(static_cast<size_t>(mPresentState));
    }
    void HandleInput() { GetState()->HandleInput(); }

    Plane& GetPlane() { return mPlane; }
    void PushPolygon(Polygon* p) { mPolygons.push_back(p); }
    void PopPolygon() { mPolygons.pop_back(); }
    bool ExistsActivePolygon() const {
        return mActivePolygon < mPolygons.size();
    }

    void MoveBox(Point<int> p) { mBox.Move(p); }
    void MovePlaneForward() { mPlane.MoveForward(); }
    void MovePlaneBackward() { mPlane.MoveBackward(); }
    void MovePlaneRight() { mPlane.MoveRight(); }
    
    Polygon* GetActivePolygon() { return mPolygons[mActivePolygon];}

    void ChangeState(StateEnum nextState) {
        if (nextState != mPresentState) {
            GetState()->OnExit();
            mPresentState = nextState;
            GetState()->OnEnter();
        }
    }

    bool FallTimeElapsed() {
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(
                now  - mLastBoxFall).count()
            > mFallTimeMilli) 
            {
                mLastBoxFall = now;
                return true;
            }
        return false;
    }

    void MoveBox() { mBox.Move(mBoxDirection); }
    void SetBoxDirection(Point<int> p) { mBoxDirection = p; }
    
    // bool BoxMustFall(std::chrono::steady_clock::time_point now)
    //     const  {
        
    //     auto elapsed =
    //         std::chrono::duration_cast<std::chrono::milliseconds>(
    //             now - mLastBoxFall).count();
            
    //     return elapsed > mFallTimeMilli;
    // }

    void SetBoxFallTime() {
        mLastBoxFall = std::chrono::steady_clock::now();

    }

    // void SetBoxFallTime() {
    //     mLastBoxFall = std::chrono::steady_clock::now();
    // }

};


#endif
