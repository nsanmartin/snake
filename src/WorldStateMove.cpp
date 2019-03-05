#include <SDL2/SDL.h>
#include <State/WorldStateMove.hpp>

void WorldStateMove::HandleInput() {
    SDL_Event event;
    int displ{};
    while( SDL_PollEvent( &event ) ) {
        switch( event.type ){
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym ) {

            case SDLK_LEFT:
                if (mWorld.ExistsActivePolygon()) {
                    mWorld.GetActivePolygon()->MoveX(-2);
                }
                break;

            case SDLK_RIGHT:
                if (mWorld.ExistsActivePolygon()) {
                    mWorld.GetActivePolygon()->MoveX(2);
                }

                break;

            case SDLK_UP:
                if (mWorld.ExistsActivePolygon()) {
                    mWorld.GetActivePolygon()->MoveY(-2);
                }
                break;

            case SDLK_DOWN:
                if (mWorld.ExistsActivePolygon()) {
                    mWorld.GetActivePolygon()->MoveY(2);
                }

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
                    displ = 5;
                } else {
                    displ = -5;
                }
                mWorld.MoveBox(Point<int>{displ, 0, 0});
                break;
                
            case SDLK_y:
                if (event.key.keysym.mod & KMOD_SHIFT) {
                    displ = 5;
                } else {
                    displ = -5;
                }
                mWorld.MoveBox(Point<int>{0, displ, 0});
                break;

            case SDLK_z:
                if (event.key.keysym.mod & KMOD_SHIFT) {
                    displ = 5;
                } else {
                    displ = -5;
                }
                mWorld.MoveBox(Point<int>{0, 0, displ});
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

}

void WorldStateMove::OnEnter() {
                
}

void WorldStateMove::OnExit() {
    mWorld.PopPolygon();
}
