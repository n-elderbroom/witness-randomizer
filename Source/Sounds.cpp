#include <sndfile.h>
#include <vector>
#include <algorithm>
#include <random>
#include "Sounds.h"
#include "Memory.h"





std::vector<uint8_t> build_sound(std::vector<Note> notes) {

	std::vector<AudioData> sounds; 
	SF_INFO info;

	for (auto note : notes) {
		std::string filename;
		if (note.is_long) {
			switch (note.note)
			{
			case VeryHigh:
				filename = "sounds/very_high_long_1.wav";
				break;
			case High:
				filename = "sounds/high_long_1.wav";
				break;
			case Mid:
				filename = "sounds/mid_long_1.wav";
				break;
			case Low:
				filename = "sounds/low_long_1.wav";
				break;
			case VeryLow:
				filename = "sounds/very_low_long_1.wav";
				break;
			}
		}
		else {
			switch (note.note)
			{
			case VeryHigh:
				filename = "sounds/very_high_1.wav";
				break;
			case High:
				filename = "sounds/high_1.wav";
				break;
			case Mid:
				filename = "sounds/mid_1.wav";
				break;
			case Low:
				filename = "sounds/low_1.wav";
				break;
			case VeryLow:
				filename = "sounds/very_low_1.wav";
				break;
			}
		}
		std::vector<float> buffer;
		SNDFILE* file = sf_open(filename.c_str(), SFM_READ, &info);

		if (!file) {
			// todo handle error?
		}

		int total_frames = info.frames * info.channels;
		buffer.resize(total_frames);
		auto frames_written = sf_read_float(file, buffer.data(), total_frames);

		sf_close(file);

		AudioData sound;
		sound.data = buffer;
		sound.framecount = total_frames;
		sounds.push_back(sound);
	}

	SF_INFO out_info = {};
	out_info.samplerate = info.samplerate;
	out_info.channels = info.channels;
	out_info.format = info.format;

	SNDFILE* outfile = sf_open("sounds/output.wav", SFM_WRITE, &out_info); //TODO its better to do this in memory with sf_open_virtual? Can avoid disk I/O that way.
	
	if (!outfile) {
		//TODO handle error? if this i/o fails there are bigger problems.
	}

	// concat all sounds
	for (const auto& s : sounds) {
		sf_write_float(outfile, s.data.data(), s.framecount);
	}
	sf_close(outfile);

	auto m = Memory::get();
	return m->readFileToVector("sounds/output.wav");
}