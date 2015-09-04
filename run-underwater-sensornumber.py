# Script for running the underwater simulation (compare NDN, consumer-driven model and producer-driven model)
# Meng Kuai
# 8/25/2015

import sys
import os
from random import randint
import matplotlib as mpl
import numpy as np

mpl.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import collections

# for plot
list_Satisfication_NDN = []
list_Satisfication_Producer = []
list_Satisfication_Consumer = []

list_Delay_NDN = []
list_Delay_Producer = []
list_Delay_Consumer = []

list_AverageDelay_NDN = []
list_AverageDelay_Producer = []
list_AverageDelay_Consumer = []

list_Overhead_NDN = []
list_Overhead_Producer = []
list_Overhead_Consumer = []

n_RunningTime = 30000  # seconds
n_Depth = 200
n_Distance = 3000
n_PacketSize = 10

list_SensorNumber = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
n_Interval1 = 400
n_Interval2 = 800

f_Frequency1 = 1 / float(n_Interval1)
f_Frequency2 = 1 / float(n_Interval2)

n_ProducerId = 1
n_Run = 1
if len(sys.argv) > 1:
    n_Run = int(sys.argv[1])

for n_SensorNumber in list_SensorNumber:

    # -------------------------------------------------
    # run ndn
    os.system('./waf --run="underwater-ndn-cw '
              '--time=%d --numberOfSensors=%d --frequency1=%f --frequency2=%f '
              '--WaterDepth=%d --distance=%d --producer=%d --run=%d"'
              % (n_RunningTime, n_SensorNumber, f_Frequency1, f_Frequency2, n_Depth, n_Distance,
                 n_ProducerId, n_Run))

    # analyze trace file
    n_Rx = 0
    n_Tx = 0
    n_DataReceived = 0
    list_Delay = []
    file_Trace = open('results/app-delays-trace.txt', "r")
    next(file_Trace)
    for line in file_Trace:
        list_Item = line.rstrip().split("\t")
        str_Type = str(list_Item[4])
        f_Delay = float(list_Item[5])
        if str_Type == "FullDelay":
            n_DataReceived += 1
            list_Delay.append(f_Delay)
    file_Trace.close()
    list_Delay_NDN.append(list_Delay)

    n_InterestSend = n_RunningTime / n_Interval1 + n_RunningTime / n_Interval2 + 1
    f_Satisfication = float(n_DataReceived) / n_InterestSend
    list_Satisfication_NDN.append(f_Satisfication)

    n_Tx = n_RunningTime / n_Interval1 + 1
    list_Overhead_NDN.append(float(n_Tx + n_DataReceived) / n_DataReceived)

    # print list_Delay_NDN

    # -------------------------------------------------
    # run consumer-driven
    os.system('./waf --run="underwater-consumer-cw '
              '--time=%d --numberOfSensors=%d --interval1=%d --interval2=%d '
              '--WaterDepth=%d --distance=%d --producer=%d --run=%d"'
              % (n_RunningTime, n_SensorNumber, n_Interval1, n_Interval2, n_Depth, n_Distance,
                 n_ProducerId, n_Run))
    # analyze trace file
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
    list_Satisfication_Consumer.append(f_Satisfication)

    list_Overhead_Consumer.append(float(n_Tx) / n_Rx)

    # print list_Delay_Consumer

    # -------------------------------------------------
    # run producer-driven
    os.system('./waf --run="underwater-producer-cw '
              '--time=%d --numberOfSensors=%d --interval1=%d --interval2=%d '
              '--WaterDepth=%d --distance=%d --producer=%d --run=%d"'
              % (
                  n_RunningTime, n_SensorNumber, n_Interval1, n_Interval2, n_Depth, n_Distance,
                  n_ProducerId,
                  n_Run))
    # analyze trace file
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
    list_Delay_Producer.append(list_Delay)

    if n_RunningTime % n_Interval1 == 0:
        n_Req = n_RunningTime / n_Interval1
    else:
        n_Req = n_RunningTime / n_Interval1 + 1
    f_Satisfication = float(n_Rx) / n_Req
    list_Satisfication_Producer.append(f_Satisfication)

    n_Tx = n_Req
    list_Overhead_Producer.append(float(n_Tx) / n_Rx)

    # print list_Delay_Producer

# Plot: Satisfication Ratio
line_NDN = plt.plot(list_SensorNumber, list_Satisfication_NDN)
line_Consumer = plt.plot(list_SensorNumber, list_Satisfication_Consumer)
line_Producer = plt.plot(list_SensorNumber, list_Satisfication_Producer)

plt.setp(line_NDN, color='r', marker='s', label='NDN')
plt.setp(line_Consumer, color='b', marker='o', label='Consumer-driven')
plt.setp(line_Producer, color='g', marker='x', label='Producer-driven')

plt.legend(loc=0)

plt.title("Satisfication Ratio")
plt.ylabel("Satisfication Ratio")
plt.xlabel("Sensor Number")

pp = PdfPages('SatisficationRatio-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()

# Plot: average delay

for l in list_Delay_NDN:
    list_AverageDelay_NDN.append(sum(l) / float(len(l)))

for l in list_Delay_Consumer:
    list_AverageDelay_Consumer.append(sum(l) / float(len(l)))

for l in list_Delay_Producer:
    list_AverageDelay_Producer.append(sum(l) / float(len(l)))

line_NDN = plt.plot(list_SensorNumber, list_AverageDelay_NDN)
line_Consumer = plt.plot(list_SensorNumber, list_AverageDelay_Consumer)
line_Producer = plt.plot(list_SensorNumber, list_AverageDelay_Producer)

plt.setp(line_NDN, color='r', marker='s', label='NDN')
plt.setp(line_Consumer, color='b', marker='o', label='Consumer-driven')
plt.setp(line_Producer, color='g', marker='x', label='Producer-driven')

plt.legend(loc=0)

plt.title("Average Delay")
plt.ylabel("Average Delay")
plt.xlabel("Sensor Number")

pp = PdfPages('AverageDelay-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()

# Plot: overhead ratio

line_NDN = plt.plot(list_SensorNumber, list_Overhead_NDN)
line_Consumer = plt.plot(list_SensorNumber, list_Overhead_Consumer)
line_Producer = plt.plot(list_SensorNumber, list_Overhead_Producer)

plt.setp(line_NDN, color='r', marker='s', label='NDN')
plt.setp(line_Consumer, color='b', marker='o', label='Consumer-driven')
plt.setp(line_Producer, color='g', marker='x', label='Producer-driven')

plt.legend(loc=0)

plt.title("Overhead Ratio")
plt.ylabel("Overhead Ratio")
plt.xlabel("Sensor Number")

pp = PdfPages('OverheadRatio-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()

# Plot: delay distribution: NDN

bp_NDN = plt.boxplot(list_Delay_NDN)
plt.axes().set_xticklabels(list_SensorNumber)

plt.title("Delay Distribution (NDN)")
plt.ylabel("Delay")
plt.xlabel("Sensor Number")

pp = PdfPages('DelayNDN-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()

# Plot: delay distribution: Consumer

bp_Consumer = plt.boxplot(list_Delay_Consumer)
plt.axes().set_xticklabels(list_SensorNumber)

plt.title("Delay Distribution (Consumer-driven)")
plt.ylabel("Delay")
plt.xlabel("Sensor Number")

pp = PdfPages('DelayConsumer-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()

# Plot: delay distribution: Producer

bp_Producer = plt.boxplot(list_Delay_Producer)
plt.axes().set_xticklabels(list_SensorNumber)

plt.title("Delay Distribution (Producer-driven)")
plt.ylabel("Delay")
plt.xlabel("Sensor Number")

pp = PdfPages('DelayProducer-Sensors.pdf')
plt.savefig(pp, format='pdf')
pp.close()
plt.close()
