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
#include <map>
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

typedef struct sipmInfo {

	int plateN;
	int fiberN;
} sipmInfo;

typedef struct moduleinfo {

	int Nmodule;
	int Ntower;
	int isCeren;
	int isSiPM;
	sipmInfo SiPM;
} moduleinfo;

int mid, ch, module, tower, isCeren, isSiPM, plate, fiber;
std::map<std::pair<int, int>, moduleinfo> mapping;

in.open("./include/mapping_data_MCPPMT_positiveSignal.csv",std::ios::in);
while (true) {
	in >> mid >> ch >> module >> tower >> isCeren >> isSiPM >> plate >> fiber;
	if (!in.good()) break;

	sipmInfo tmpSiPM;
	if ( isSiPM == 0 ) tmpSiPM = {0, 0};
	if ( isSiPM == 1 ) tmpSiPM = {plate, fiber};
	moduleinfo tmpModule = {module, tower, isCeren, isSiPM, tmpSiPM};
	mapping.insert(std::make_pair(std::make_pair(mid, ch), tmpModule));
}
in.close();

typedef struct DataStruct {
	std::vector< std::vector<int> > waveform;
} DataStruct; 

std::string BASE_DIR  = "/Users/khwang/scratch/TestBeam/";
std::string RUNNUMBER = "1";
std::string DATA_DIR  = "/Users/khwang/scratch/TestBeam/sampleData/";
std::string FILE_NAME = "run_1_wave";

double HeatADCmax = 3000.;
double DistADCmax = 3000.;

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