#include <iostream>
#include <chrono>
#include <thread>


#include <World.hpp>
#include <State/WorldStatePresentation.hpp>
#include <State/WorldStateMove.hpp>

World::World()
    : mContinue{true}, mMedia{*this},
      mBoard{20 /*width*/, 20/*height*/, 20/*depth*/},
      mBlockPos{},
      mNormal{},
      mPlane{Point<double>{0.1, 0.1, 1.0}},
      mBox{80, 80, 80},
      mBoxDirection{0,1,0},
      mFallTimeMilli{20},
      mActivePolygon{},
      mStates{new WorldStatePresentation{*this},
              new WorldStateMove{*this}},
      mPresentState{}
{
    mBox.CenterAt(mMedia.GetWindowCenter());
}


World::~World() {
    for (auto state : mStates) { delete state; }
    for (auto poly : mPolygons) { delete poly; }
}

void World::Loop() {
    mMedia.Init();

    while (mContinue) {
        HandleInput();
        Update();
        mMedia.Clear();
        //for (auto& cajita : mCajitas) { mMedia.Draw(cajita); }
        for (auto poly : mPolygons) { poly->Draw(mMedia); }
        mBox.Draw(mMedia);
        mMedia.PresentScreen();
        
        std::this_thread::sleep_for(
            std::chrono::milliseconds(16));
        
    }
    
    mMedia.Close();
    std::cout << "bye" << std::endl;
}


void World::Update() {
    GetState()->Update();
}

