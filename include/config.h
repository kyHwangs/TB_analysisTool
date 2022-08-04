#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <TPad.h>
#include <utility>
#include <iostream>

// NOTE : update enum!
//			1. monit
//				a. waveform
//				b. fast mode
//			2. pedstal num and type
//			3. run num and mode
//			4. specific?

// enum discriminator {
// 	kIntegral = 0,
// 	kPeak,
// 	kPed,
// 	kWaveform,
// 	kTiming,
// 	kTest
// };

// enum runMode {
// 	kFull = 0,
//     kPrompt,
//     kCoarse,
//     kNoPed
// };

typedef struct DataStruct {
	std::vector< std::vector<int> > waveform;
} DataStruct; 

std::string BASE_DIR  = "/Users/khwang/scratch/TestBeam/";
std::string RUNNUMBER = "1";
std::string DATA_DIR  = "/Users/khwang/scratch/TestBeam/sampleData/";
std::string FILE_NAME = "run_1_wave";

std::vector<std::string> LoadedFiles;

// int NofDAQModule = 10;

// std::vector<std::vector<int>> chInput   {
// 											{0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15,
// 											 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
// 											{0, 8, 16}
// 										};

// std::vector<std::vector<int>> plotColor {
// 											{1, 600, 632, 416, 800, 416, 616, 432, 
// 										     1, 600, 632, 416, 800, 416, 616, 432,
// 										     1, 600, 632, 416, 800, 416, 616, 432,
// 										     1, 600, 632, 416, 800, 416, 616, 432}
// 										};

// std::vector<TString> plotName = {
//                                 "#font[42]{#scale[0.8]{Ext Trigg. 1}}",
//                                 "#font[42]{#scale[0.8]{Ext Trigg. 2}}",
//                                 "#font[42]{#scale[0.8]{Discriminator}}"
//                                 };




// kWhite  = 0,   kBlack  = 1,   kGray    = 920,  kRed    = 632,  kGreen  = 416,
// kBlue   = 600, kYellow = 400, kMagenta = 616,  kCyan   = 432,  kOrange = 800,
// kSpring = 820, kTeal   = 840, kAzure   =  860, kViolet = 880,  kPink   = 900
