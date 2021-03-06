#ifndef _WORLD_STATE_PRESENTATION_H
#define _WORLD_STATE_PRESENTATION_H

#include <World.hpp>
#include <State/WorldState.hpp>

class WorldStatePresentation : public WorldState {
    World& mWorld;
public:
    WorldStatePresentation(World& w) : mWorld{w} {}
    void HandleInput() override;
    void Update() override;
    void OnEnter() override;
    void OnExit() override;

};

#endif
