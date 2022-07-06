import sys, os
import argparse
import ROOT
from plugin.functions import convert_args_to_enum, get_commands, init_directories ## custom functions
ROOT.PyConfig.ShutDown = False

## Using argument parser
parser = argparse.ArgumentParser()
parser.add_argument('--config', '-c', action='store', type=str, default='config.h', help='Path of header file with configs')
parser.add_argument('--runNum', '-r', action='store', type=str, required=True, help='Run number of data')
parser.add_argument('--pedNum', '-pn', action='store', type=str, default='-1', help='Pedestal file number')
parser.add_argument('--type', '-t', action='store', type=str, required=True, help='[kPed, kWaveform, kIntegral, kPeak]')
parser.add_argument('--pedType', '-pt', action='store', type=str, default='-1', help='[kFull, kPrompt, kCoarse]')
parser.add_argument('--debug', '-d', action='store_true', default=False, help='Activate debug mode, will print out debug info')
args = parser.parse_args()

type_dict = convert_args_to_enum(args)

if args.debug :
    print('Will execute macro with types')
    for keys in type_dict :
        print(keys,':',type_dict[keys])

config_cmd, macro_cmd = get_commands(args, type_dict)


if args.debug :
    print("Reading header :", args.config)
    print("Executing macro :", macro_cmd[3:])

ROOT.gInterpreter.ProcessLine(config_cmd) 
init_directories(ROOT.BASE_DIR, args.runNum)           
ROOT.gInterpreter.ProcessLine(macro_cmd)

if args.type == "kIntegral" and args.type == "kPeak" :
    input()
