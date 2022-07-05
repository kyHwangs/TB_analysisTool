import os, sys
import ROOT

def convert_args_to_enum(arguments):

    type_dict            = {'type': 0, 'pedType': 0, 'moduleType' : 0}

    candIntegral         = ['kIntegral', 'integral', 'int', 'i']
    candPeak             = ['kPeak', 'peak', 'pk']
    candWaveform         = ['kWaveform', 'waveform', 'wave', 'w']
    candTime             = ['kTiming', 'timing', 'time', 't']
    candPed              = ['kPed', 'ped', 'pd']

    candFullPed          = ['kFull', 'full', 'f']
    candPrompyPed        = ['kPrompt', 'prompt', 'ppt', 'p']
    candCoarsePed        = ['kCoarse', 'coarse', 'cs', 'c']
    candNoPed            = ['kNoPed', 'noPed', 'noped', 'no', 'np', 'n']
    candDummyPed         = ['-1']

    candGenericPMT       = ['kGenericPMT', 'genericPMT', 'genericpmt', 'gen', 'genpmt', 'pmt']
    candSiPM             = ['kSiPM', 'sipm', 's']
    candMCPPMT           = ['kMCPPMT', 'mcppmt', 'mcp']

    if arguments.type in candIntegral :
        type_dict['type'] = 'kIntegral'
    if arguments.type in candPeak :
        type_dict['type'] = 'kPeak'
    if arguments.type in candWaveform :
        type_dict['type'] = 'kWaveform'
    if arguments.type in candTime :
        type_dict['type'] = 'kTiming'
    if arguments.type in candPed :
        type_dict['type'] = 'kPed'

    if arguments.pedType in candFullPed :
        type_dict['pedType'] = 'kFull'
    if arguments.pedType in candPrompyPed :
        type_dict['pedType'] = 'kPrompt'
    if arguments.pedType in candCoarsePed :
        type_dict['pedType'] = 'kCoarse'
    if arguments.pedType in candNoPed :
        type_dict['pedType'] = 'kNoPed'
    if arguments.pedType in candDummyPed :
        type_dict['pedType'] = 'kDummyPed'

    type_dict['moduleType'] = 'kGenericPMT'
    
    # if arguments.module in candGenericPMT :
    #     type_dict['moduleType'] = 'kGenericPMT'
    # if arguments.module in candSiPM :
    #     type_dict['moduleType'] = 'kSiPM'
    # if arguments.module in candMCPPMT :
    #     type_dict['moduleType'] = 'kMCPPMT'

    return type_dict


def get_commands(arguments, type_dict):

    run_type = type_dict['type']
    ped_type = type_dict['pedType']
    mud_type = type_dict['moduleType']

    config_cmd = "#include \"%s\"" % (arguments.config)

    if (run_type == 'kPed'):
        macro_cmd = ".x ./src/CalcPed.cc(\"%s\")" % (arguments.runNum)

    if (run_type == 'kWaveform'):
        if(mud_type == 'kGenericPMT'):
            macro_cmd = ".x ./src/BaseWaveform_GenericPMT.cc(\"%s\")" % (arguments.runNum)
        # if(mud_type == 'kSiPM'):
        #     macro_cmd = ".x ./src/BaseWaveform_SiPM.cc(\"%s\")" % (arguments.runNum)
        # if(mud_type == 'kMCPPMT'):
        #     macro_cmd = ".x ./src/BaseWaveform_MCPPMT.cc(\"%s\")" % (arguments.runNum)

    if (run_type == 'kIntegral'):
        if(mud_type == 'kGenericPMT'):
            macro_cmd = ".x ./src/BaseIntegral_GenericPMT.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)
        # if(mud_type == 'kSiPM'):
        #     macro_cmd = ".x ./src/BaseIntegral_SiPM.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)
        # if(mud_type == 'kMCPPMT'):
        #     macro_cmd = ".x ./src/BaseIntegral_MCPPMT.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)

    if (run_type == 'kPeak'):
        if(mud_type == 'kGenericPMT'):
            macro_cmd = ".x ./src/BasePeak_GenericPMT.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)
        # if(mud_type == 'kSiPM'):
        #     macro_cmd = ".x ./src/BasePeak.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)
        # if(mud_type == 'kMCPPMT'):
        #     macro_cmd = ".x ./src/BasePeak.cc(\"%s\", \"%s\", %s)" % (arguments.runNum, arguments.pedNum, ped_type)

    return config_cmd, macro_cmd

def init_directories(baseDir, runNum, run_type) :

    dir_list = [
                'Peak',
                'Integral',
                'Timing',
                # 'Ped/Prompt',
                # 'Ped/Full',
                'Waveform'
               ]

 
    ped_list = [
                'Ped/Prompt',
                'Ped/Full'
               ]

    baseDir = os.path.join(baseDir, ROOT.SCENARIO, runNum)
    if not (os.path.exists(baseDir)) :
        os.makedirs(baseDir)

        if not (run_type == 'kPed') :

            for dirs in dir_list :
                required_dir = os.path.join(baseDir, dirs)
                os.makedirs(required_dir)

                if not (dirs == 'Timing' or dirs == 'Integral' or dirs == 'Peak') :

                    for n, i in enumerate(ROOT.chInput) :
                        modDir = os.path.join(required_dir, str(n+1))
                        os.makedirs(modDir)

        elif run_type == 'kPed' :

            for dirs in ped_list :
                required_dir = os.path.join(baseDir, dirs)
                os.makedirs(required_dir)

                for n, i in enumerate(ROOT.chInput) :
                    modDir = os.path.join(required_dir, str(n+1))
                    os.makedirs(modDir)

