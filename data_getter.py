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
header = "id,s0,s1,s2,s3,s4,s5,s6,s7,timestamp"
first = True

with open(args.outfile,"w") as f:
    while 1:
        if first:
            f.writelines(header)
            first = False
        line = ser.readline()
        cur_id = line.split(",")[0]
        if cur_id <= args.max_id:
            f.writelines(line)
        else:
            break

#Data Process with Panda
method = ['max','mean']

df1 = pd.read_csv(args.outfile).drop('timestamp')

for m in method:
    if m =='max':
        df1.groupby("id",axis=1).max().to_csv("max_"+args.outfile)
    elif m =='mean':
        df1.groupby("id",axis=1).mean().to_csv("mean_"+args.outfile)