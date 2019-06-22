import serial
import argparse
import pandas as pd 


parser = argparse.ArgumentParser(description="Data Getter parameters from Arduino")

parser.add_argument('--baud_rate',type=int,help='Baud rate from Arduino')
parser.add_argument('--port',type=str,help='Com port from PC')
parser.add_argument('--max_id',type=int,help='max number of id')
parser.add_argument('--outfile',type=str,help='name of output file')

args = parser.parse_args()

print(args.baud_rate,type(args.baud_rate))
print(args.port,type(args.port))
print(args.max_id,type(args.max_id))
print(args.outfile,type(args.outfile))

count = 0

ser = serial.Serial(args.port,args.baud_rate)


with open(args.outfile,"w") as f:
    while 1:
        line = ser.readline()
        cur_id = line.split(",")[0]
        if cur_id <= args.max_id:
            f.write(line)
        else:
            break