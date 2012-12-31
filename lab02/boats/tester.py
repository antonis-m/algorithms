import os

count = raw_input()

for i in range(int(count)):
	print i+1	
	os.system("time ./boats < input"+str(i+1)+".txt")
	os.system("cat output"+str(i+1)+".txt")
