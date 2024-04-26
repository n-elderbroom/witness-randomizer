#include "TextureLoader.h"
#include "Panel.h"
#include <wtx_tools.h>
#include "Memory.h"
#include <iostream>
#include <fstream>

TextureLoader* TextureLoader::_singleton = nullptr;

void TextureLoader::generateColorBunkerTexture(int32_t panelid)
{
	auto p = new Panel(panelid);

	// need to flatten _grid into one contiguous array so that rust-code can read it safely. 
	std::vector<int> flattened;
	for (auto row : p->_grid) {
		for (auto element : row) {
			flattened.push_back(element);
		}
	}

	auto bg = ColorPanelBackground::Blueprint;
	switch (p->id) {
	case 0x0A010:
	case 0x0A01B:
		bg = ColorPanelBackground::LightGrey;
		break;
	case 0x0A01F:
		bg = ColorPanelBackground::DarkGrey;
		break;
	case 0x17E63:
	case 0x17E67:
		bg = ColorPanelBackground::White;
		break;
	case 0x0A079:
		bg = ColorPanelBackground::Elevator;
		break;
	}


	TextureBuffer tex = wtx_tools_generate_colorpanel_from_grid((const uint32_t*)&flattened[0], p->_width, p->_height, bg);
	// Rust will continue to hold some knowledge of that memory it allocated to return the `tex`
	// so we should copy the data to a local variable, and tell rust that we are done and it can free that memory safely.
	std::vector<uint8_t> wtxBuffer = std::vector<uint8_t>(tex.data, tex.data + tex.len);

	//let rust free the memory it allocated
	free_texbuf(tex);

	storedTextures[textureNames[panelid]] = wtxBuffer;
}



//Read a texture from disk, converting it and queueing it for load in-game
//Mostly for easy testing of custom textures.
//Format should be an enum, DXT1 or DXT5 depending on the texture you are replacing
//most larger textures are DXT5. DXT5 also supports alpha.
//The "bits" is used internally, but its unclear what exactly for
//most diffuse / colorful textures set bits to 1
//spec maps and other greyscale images flip bit with value 4
//	...but also the desert panels have value 1? so the bits get set to 5 total.
//textures with alpha might flip bit 2?
//bit 8 seems to be cube maps / "probes" like reflection maps? they are structured differently
//This function does *not* currently auto-load the relevent package. 
void TextureLoader::readTextureFromDisk(std::string filename, std::string texturenameingame, TextureEncodeFormat format, uint8_t bits = 1) {
	std::ifstream fileBuffer(filename, std::ios::ate | std::ios::binary);

	if (fileBuffer.is_open()) {
		std::streamsize length = fileBuffer.tellg();
		fileBuffer.seekg(0, std::ios::beg);
		char* buffer = new char[length];
		fileBuffer.read(buffer, length);
		ImgFileBuffer inputfile;
		inputfile.data = buffer;
		inputfile.len = length;

		WtxFormat rustenumformat;
		if (format == TextureEncodeFormat::DXT1) {
			rustenumformat = WtxFormat::DXT1;
		} else if (format == TextureEncodeFormat::DXT5) {
			rustenumformat = WtxFormat::DXT5;
		}
			

		TextureBuffer tex = image_to_wtx(inputfile, true, rustenumformat, bits);

		// Rust will continue to hold some knowledge of that memory it allocated to return the `tex`
		// so we should copy the data to a local variable, and tell rust that we are done and it can free that memory safely.
		std::vector<uint8_t> wtxBuffer = std::vector<uint8_t>(tex.data, tex.data + tex.len);

		//let rust free the memory it allocated
		free_texbuf(tex);
		storedTextures[texturenameingame] = wtxBuffer;
	}
	else {
		1 + 1;
	}
}


TextureLoader* TextureLoader::get()
{
	if (_singleton == nullptr) {
		_singleton = new TextureLoader();
	}
	return _singleton;
}

void TextureLoader::loadTextures()
{
	Memory* memory = Memory::get();
	memory->LoadPackage("save_58472"); //tells game to load the color bunker assets into memory, so we can edit them
	//memory->LoadPackage("save_58392"); // desert panels
	//memory->LoadPackage("save_58473"); // desert panels
	//memory->LoadPackage("save_58413"); // desert panels
	//memory->LoadPackage("globals"); // one single desert panel is in "globals" its probably already always loaded?
	//memory->LoadPackage("save_58421"); //this package has the town area spec panels

	//readTextureFromDisk("./test.png", "obj_panels_color_tricolor_1", DXT5, 1);
	

	for (auto& elem : storedTextures) {
		auto texturename = elem.first;
		auto texmap = memory->GetTextureMapFromCatalog(texturename);
		memory->LoadTexture(texmap, elem.second);
		storedTexMaps[elem.first] = texmap; //store the tex map. (in case we want to unload it some day)
	}
}

void TextureLoader::generateTexture(int32_t panelid)
{

	switch (panelid) {
	case 0x09F7D:
	case 0x09FDC:
	case 0x09FF7:
	case 0x09F82:
	case 0x09FF8:
	case 0x09D9F:
	case 0x09DA1:
	case 0x09DA2:
	case 0x09DAF:
	case 0x0A010:
	case 0x0A01B:
	case 0x0A01F:
	case 0x17E63:
	case 0x17E67:
	case 0x0A079:
		generateColorBunkerTexture(panelid);
	}
	
}
