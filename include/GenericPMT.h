#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <TPad.h>
#include <utility>
#include <iostream>

enum discriminator {
	kIntegral = 0,
	kPeak,
	kPed,
	kWaveform,
	kTiming,
	kTest
};

enum runMode {
	kFull = 0,
    kPrompt,
    kCoarse,
    kNoPed
};

std::string BASE_DIR = "/home/${USER}/TB_analysisTool/";
std::string SCENARIO = "result";
std::string DATA_DIR = "/home/${USER}/TB_analysisTool/sampleData/";
std::string FILE_NAME = "ele18MeV";

int NofDAQModule = 1;

std::vector<std::vector<int>> chInput   {
											{0, 4, 10, 14, 16}
									    };

std::vector<std::vector<int>> plotColor {
											{1, 634, 602, 1, 433}
										};


std::vector<std::vector<TString>> plotName = {
											 	{
					                                "#font[42]{#scale[0.8]{Ext Trigg. 1}}",
					                                "#font[42]{#scale[0.8]{Module B - #color[634]{S ch}}}",
					                                "#font[42]{#scale[0.8]{Module B - #color[602]{C ch}}}",
					                                "#font[42]{#scale[0.8]{Ext Trigg. 2}}",
					                                "#font[42]{#scale[0.8]{Veto}}"
                                				}
                                			};




// kWhite  = 0,   kBlack  = 1,   kGray    = 920,  kRed    = 632,  kGreen  = 416,
// kBlue   = 600, kYellow = 400, kMagenta = 616,  kCyan   = 432,  kOrange = 800,
// kSpring = 820, kTeal   = 840, kAzure   =  860, kViolet = 880,  kPink   = 900
