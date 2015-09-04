import os

for run in range(1, 20):
    os.system('python run-underwater-sensornumber.py %d' % run)
    os.system('python run-underwater-interval.py %d' % run)
    os.system("mkdir results/%d" % run)
    os.system("mv *.pdf results/%d" % run)