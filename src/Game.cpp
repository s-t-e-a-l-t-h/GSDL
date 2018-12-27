//
// Created by mike on 27.12.2018.
//

#include "Game.h"


Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    Uint32 sdl_window_flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;


    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsystems initialised!..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, sdl_window_flags);
        if(window) std::cout << "window created" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            std::cout << "renderer created" << std::endl;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        setIsRunning();

    } else {
        setIsNotRunning();
    }


}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            setIsNotRunning();
        } break;

        default:
            break;
    }
}

void Game::update() {

}

void Game::render() {
    SDL_RenderClear(renderer);
    // add render stuff
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}

bool Game::running() {
    return isRunning;
}

bool Game::setIsRunning() {
    isRunning = true;
}

bool Game::setIsNotRunning() {
    isRunning = false;
}