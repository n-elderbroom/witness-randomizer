#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>
#include "TextureLoader.h"

enum TextureEncodeFormat {
	DXT1,
	DXT5
};

class TextureLoader
{
	// texture name -> wtx
	std::unordered_map < std::string, std::vector<uint8_t> > storedTextures;
	// wtx -> in-game texmap
	std::unordered_map < std::string, uint64_t > storedTexMaps;


	void generateColorBunkerTexture(int32_t panelid);

protected:

	static TextureLoader* _singleton;

public:

	static TextureLoader* get();
	void loadTextures();
	void generateTexture(int32_t panelid);

	void readTextureFromDisk(std::string filename, std::string texturenameingame, TextureEncodeFormat format, uint8_t bits);

};

inline std::unordered_map<int32_t, std::string> textureNames = {
	{0x09F7D, "obj_panels_color_tricolor_1"},
	{0x09FDC, "obj_panels_color_tricolor_2"},
	{0x09FF7, "obj_panels_color_tricolor_3"},
	{0x09F82, "obj_panels_color_tricolor_4"},
	{0x09FF8, "obj_panels_color_tricolor_5"},
	{0x09D9F, "obj_panels_color_tricolorNew_A"},
	{0x09DA1, "obj_panels_color_tricolorNew_B"},
	{0x09DA2, "obj_panels_color_tricolorNew_C"},
	{0x09DAF, "obj_panels_color_tricolorNew_D"},
	{0x0A010, "obj_panels_color_colorfilter_1"},
	{0x0A01B, "obj_panels_color_colorfilter_2"},
	{0x0A01F, "obj_panels_color_colorfilter_3"},
	{0x17E63, "obj_panels_color_coloredlight_1"},
	{0x17E67, "obj_panels_color_coloredlight_2"},
	{0x0A079, "obj_panels_color_tricolorNew_Elevator"},

	{0x00698, "panel_spec1"}, // Desert Surface 1
	{0x0048F, "panel_spec_shadow_block"}, // Desert Surface 2 (shadow is blocked by a rock)
	{0x09F92, "panel_spec_slide"}, // Desert Surface 3 (panel slides around)
	{0x0A036, "panel_spec_4way_1"}, // Desert Surface 4 (left top)
	{0x09DA6, "panel_spec_4way_2"}, // Desert Surface 5 (middle top)
	{0x0A049, "panel_spec_4way_3"}, // Desert Surface 6 (right top)
	{0x0A053, "panel_spec_4way_4"}, // Desert Surface 7 (below the middle top one)
	{0x09F94, "panel_spec_turn"}, // Desert Surface 8 (turnable panel)
	{0x00422, "spec_extra_light_1"}, // Desert Light 1 (right side)
	{0x006E3, "spec_extra_light_2"}, // Desert Light 2 (left side)
	{0x0A02D, "panel_spec_floor_grid"}, // Desert Light 3 (floor)
	{0x00C72, "specbasement-2"}, // Desert Pond 1 ///these basement hexagons are NOT solved in the order the texture names imply
	{0x0129D, "specbasement-1"}, // Desert Pond 2
	{0x008BB, "specbasement-3"}, // Desert Pond 3
	{0x0078D, "specbasement-4"}, // Desert Pond 4
	{0x18313, "specbasement-7"}, // Desert Pond 5
	{0x04D18, "specbasement-10"}, // Desert Flood 1
	{0x01205, "specbasement-6"}, // Desert Flood 2
	{0x181AB, "specbasement-9"}, // Desert Flood 3
	{0x0117A, "specbasement-5"}, // Desert Flood 4
	{0x17ECA, "spec_basement_growspot"}, // Desert Flood 5 
	{0x18076, "spec_basement_flood_final"}, // Desert Flood Exit - rectangle puzzle in flood room. (orientation different, texture is rotated 90, starting on top ending on bottom.
	
	{0x0A15F, "spec_curved_vertical"}, //Desert Final Near - final room, vertical concave?
	{0x0A15C, "spec_concave_a"}, //wide desert panel curve 1 (top) (its convex and badly named)
	{0x09FFF, "spec_concave_b"}, //wide desert panel curve 2 (bottom)
	{0x17C31, "spec_glass_panel"}, // the one glass panel toward end of desert basement
	{0x012D7, "specbasement-8"}, //Desert Final Near - last hexagon puzzle


	//Other notable textures
	
	//panel_spec_hub_triple is the spec map for the town triple solution puzzle (0x079DF)
	//hubpuzzle_fol_vinesParth-alpha is the viney plant solution for the triple solution puzzle (0x079DF)
	//hubpuzzle_fol_vinesParth-normal is the normal map for the vine solution
	 
	//panel_spec_hub_duo is bottom half of the red town panel. (0x28B39) 
	
	// sketches_puzzle_disclosure_sly is the paper that shows you the secret gate solution at the start of the game.
	// Vault boxes:
	//  sketches_code_burke
	//  sketches_code_feynman
	//  sketches_code_gagaji
	//  sketches_code_psalm46
	//  sketches_code_sagan
	//(versions of the above exist without sketches_ prefix, but i dont think are used?)
	 
	//shar_Concrete_Panel-blend is the floor puzzle right at the start of the game - after doing the pillar (0x0C373)


	//in the mountain
	//cc_halfstone - broken screen pattern
	//cc_halfstone_intro - broken screen pattern
	//cc_local- broken screen pattern
	//cc_logic - broken screen pattern
	//cc_pretty_mask - mask for the dots everone is confused about on the rainbow puzzle

};