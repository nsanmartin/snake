#include <SDL2/SDL.h>
#include <State/WorldStateMove.hpp>

void WorldStateMove::HandleInput() {
    SDL_Event event;

    while( SDL_PollEvent( &event ) ) {
        switch( event.type ){
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym ) {

            case SDLK_LEFT:
                break;

            case SDLK_RIGHT:
                break;

            case SDLK_UP:
                break;

            case SDLK_DOWN:
                break;

            case SDLK_b:
                mWorld.MovePlaneBackward();
                break;

            case SDLK_f:
                mWorld.MovePlaneForward();
                break;

            case SDLK_r:
                mWorld.MovePlaneRight();
                break;

            // case SDLK_r:
                
            //     if (mWorld.ExistsActivePolygon()) {
            //         int rot{6};

            //         if (event.key.keysym.mod & KMOD_SHIFT) {
            //             rot = 354;
            //         }

            //         mWorld.GetActivePolygon()->Rotate(rot);
            //     }

                break;

            case SDLK_q:
                mWorld.Quit();
                break;

            case SDLK_x:
                if (event.key.keysym.mod & KMOD_SHIFT) {
                    mWorld.SetBoxDirection(Point<int>{1, 0, 0});
                } else {
                    mWorld.SetBoxDirection(Point<int>{-1, 0, 0});
                }
                //mWorld.MoveBox(Point<int>{displ, 0, 0});
                break;
                
            case SDLK_y:
                if (event.key.keysym.mod & KMOD_SHIFT) {
                    mWorld.SetBoxDirection(Point<int>{0, 1, 0});
                } else {
                    mWorld.SetBoxDirection(Point<int>{0, -1, 0});
                }
                break;

            case SDLK_z:
                if (event.key.keysym.mod & KMOD_SHIFT) {
                    mWorld.SetBoxDirection(Point<int>{0, 0, 1});
                } else {
                    mWorld.SetBoxDirection(Point<int>{0, 0, -1});
                }
                break;

                
            case SDLK_ESCAPE:
                mWorld.ChangeState(
                    World::StateEnum::Presentation);
                break;

            default:
                break;
            }
            break;
        case SDL_KEYUP:
            break;

        case SDL_QUIT:
            mWorld.Quit();
            break;

        default:
            break;
        }

    }
}



void WorldStateMove::Update() {

    if (mWorld.FallTimeElapsed()) {
        // lets box fall
        mWorld.MoveBox();
    }
}

void WorldStateMove::OnEnter() {
    mWorld.SetBoxFallTime();
}

void WorldStateMove::OnExit() {
    mWorld.PopPolygon();
}
