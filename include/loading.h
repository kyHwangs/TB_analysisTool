#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <vector>

#include <cstdio>
#include <algorithm>
#include <numeric>
#include <TPad.h>
#include <utility>

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


std::vector<std::string> SortFileVec(std::vector<std::string>& RawFileVec){
	std::vector<std::string> sortedVec;

	for (int j = 0; j < RawFileVec.size(); j++) {
		std::string tmpStr = RawFileVec.at(0);
		for (int i = 0; i < RawFileVec.size() - 1; i++) {
			// sorting algo? 
		}
	}


	return sortedVec;

}

std::vector<std::string> LoadingFiles(){
	std::vector<std::string> filesVec;

    for(auto& p: std::filesystem::directory_iterator( (DATA_DIR + RUNNUMBER + "/").c_str() )) {
        filesVec.push_back(p.path());
    }

	return SortFileVec(filesVec);
}

bool isValid() {

	// checking validation?

	return true;
}

void Organization(std::vector<std::string>& FileVec, std::vector< DataStruct >) {

	for (int i = 0; i < FileVec.size(); i++) {
		LoadedFiles.push_back(FileVec.at(i))

		// file open here!

		for (int evt = 0; evt < nevt; evt++ ) {

			if (!isValid()) continue;

		}
	}
}