#include "common.h"

bool running = true;
FrameBuffer *mage_canvas;
uint32_t lastTime;
uint32_t now;
uint32_t delta_time;
#include "mage_sprites.h"

void handle_input () {
    #ifdef DC801_DESKTOP
    SDL_Event e;
    if (application_quit != 0)
    {
        running = false;
    }

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
            break;
        }

        if (e.type == SDL_KEYDOWN)
        {
            if (
                e.key.keysym.sym == SDLK_ESCAPE
                || e.key.keysym.scancode == SDL_SCANCODE_Q
            )
            {
                running = false;
                break;
            }
        }
    }

    nrf_delay_ms(5);
    #endif

    #ifdef DC01_EMBEDDED
    app_usbd_event_queue_process();
    #endif
}
#define TILE_SIZE 16

void mage_game_loop () {
    now = millis();
    delta_time = now - lastTime;

    mage_canvas->clearScreen(RGB(0,0,255));
    mage_canvas->drawHorizontalLine(10, 20, 100, RGB(0,255,0));

    mage_canvas->drawImage(
        32,
        32,
        32,
        32,
        black_mage_raw,
        0,
        0,
        32,
        0x0000
    );
    mage_canvas->drawImageFromFile(
        64,
        32,
        32,
        32,
        "MAGE/game.dat",
        0,
        0,
        32,
        0x020
    );
    mage_canvas->drawImageFromFile(
        64,
        64,
        32,
        32,
        "MAGE/game.dat",
        0,
        0,
        32
    );
    mage_canvas->drawImageFromFile(
        64,
        96,
        32,
        32,
        "MAGE/exa.dat",
        0,
        0,
        32
    );
    mage_canvas->blt();

    lastTime = now;
}

GameDataMemoryAddresses dataMemoryAddresses;
int MAGE() {
    FILE *dataFile = fopen("game.data", "rb");
    fread(
            dataFile,
            &dataMemoryAddresses.mapCount,
            sizeof(dataMemoryAddresses.mapCount)
    );
    dataMemoryAddresses.mapCount
    mage_canvas = p_canvas();
    lastTime = millis();
    while (running)
    {
        handle_input();
        mage_game_loop();
    }
    return 0;
}