import os

n_RunningTime = 30000  # seconds
n_Depth = 200
n_Distance = 3000
n_PacketSize = 10

list_SensorNumber = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
n_Interval1 = 400
n_Interval2 = 30000

f_Frequency1 = 1 / float(n_Interval1)
f_Frequency2 = 1 / float(n_Interval2)

n_ProducerId = 1
n_Run = 1

n_SensorNumber = 4

os.system('./waf --run="underwater-consumer-cw '
          '--time=%d --numberOfSensors=%d --interval1=%d --interval2=%d '
          '--WaterDepth=%d --distance=%d --producer=%d --run=%d"'
          % (n_RunningTime, n_SensorNumber, n_Interval1, n_Interval2, n_Depth, n_Distance,
              n_ProducerId, n_Run))
list_Delay_Consumer = []
n_Rx = 0
n_Tx = 0
n_Req = 0
list_Delay = []
file_Trace = open('results/output.txt', "r")
next(file_Trace)
for line in file_Trace:
    list_Item = line.rstrip().split("\t")
    f_Delay = float(list_Item[1])
    n_Rx += 1
    list_Delay.append(f_Delay)
file_Trace.close()
list_Delay_Consumer.append(list_Delay)

file_Trace = open('results/output_tx.txt', "r")
for line in file_Trace:
    n_Tx = int(line)
file_Trace.close()

if n_RunningTime % n_Interval1 == 0:
    n_Req = n_RunningTime / n_Interval1
else:
    n_Req = n_RunningTime / n_Interval1 + 1
if n_RunningTime % n_Interval2 == 0:
    n_Req += n_RunningTime / n_Interval2
else:
    n_Req += n_RunningTime / n_Interval2 + 1

f_Satisfication = float(n_Rx) / n_Req
print f_Satisfication

#print float(n_Tx)/n_Rx


'''
os.system('./waf --run="underwater-ndn-cw '
              '--time=%d --numberOfSensors=%d --frequency1=%f --frequency2=%f '
              '--WaterDepth=%d --distance=%d --producer=%d --run=%d"'
              % (n_RunningTime, n_SensorNumber, f_Frequency1, f_Frequency2, n_Depth, n_Distance,
                 n_ProducerId, n_Run))'''