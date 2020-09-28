# todo:

- [x] Add tile flipping to render function
- [x] Entities
	- [x] Determine which entity should be player character on map load
- [x] Handle player input
- [x] Add entity render ordering by coordinate of bottom edge
- [x] Add support for entity animation timing
	- [x] Make an array of uint16s that just hold the current frame for entities; it doesn't need to be hackable, just stateful
	- [x] Reset
- [x] Port over the sdl_toy_0 button & LED state emulation
	- [x] Start rendering the background graphic
	- [x] Collect the Button coordinates
	- [x] Render the Buttons
	- [x] Collect the LED coordinates
	- [x] Render the LEDs
	- [x] Handle all inputs for the buttons
	- [x] Toggle the button renderable states when buttons are down
	- [x] Toggle the LED/Boolean values when the buttons are pressed
- [x] Generate a bunch of different WAV files of different sample rates for Dovid
- [ ] Port over the Hex Editor
	- [x] Build Monaco 9 as an AdaGFXFont because we need a good monospace font
	- [x] Start rendering the text for the byte grid
	- [x] Render byte selection cursor behind the text
	- [x] Arrows navigate cursor on byte grid when hex editor is open
	- [x] Pass states of currently selected byte to the LEDs
	- [x] Build the entity RAM <-> uint8_t array mapper/typecasting?
	- [x] Build hex ops handler functions
	- [x] Trigger swap of hex ops enum
	- [x] Build hex bit handler functions
	- [x] Trigger hex bit handler to change value of bits on selected byte
	- [ ] Build MEM button handler functions
	- [ ] Trigger swap/set of MEM... position?
	- [x] Add ability to offset visible page of RAM by pages
	- [x] Render something on screen to see which RAM PAGE you're on
	- [x] Add PAGE handler; Hold page + arrows to jump pages of bytes?
	- [ ] Start adding error handling for when indexing outside of supported types ROM data
- [x] Move functions for reading from the ROM into `mage_rom.cpp`
- [ ] Create some `get_*_by_index` functions for reading from ROM
	- [ ] These should return nullptr if not found
	- [ ] Things that call these should check for null and have a fallback
	- [x] get_entity_type_by_index
	- [ ] get_entity_by_index
	- [ ] get_map_by_index
	- [x] get_tileset_by_index
	- [x] get_image_by_index
	- [ ] get_animation_by_index
	- [ ] get_animation_direction_by_index_and_direction
- [ ] In the ROM header, the first u4 should be the length of the header
	- [ ] In Mage init, Read header up to that length, then parse it
- [ ] Make a list of some C functions we want scripts to be able to call
- [ ] Decide on a common script function signature
- [ ] Define an encoding format for scripts
- [ ] Ability to specify which font is used in a dialog
	- [ ] There can be a puzzle where changing the font to smaller makes all of a message readable
- [ ] Music/SFX encoding in the binary asset encoder