import os
import time

n = 1000000000

time1 = time.time()
fp = open("input.txt", "w")
fp.write("save the world\n")
fp.close()
time2 = time.time()
n %= 18092020
time3 = time.time()

os.remove("input.txt")

print(f"time require for write a sentence to file: {time2-time1}s")
print(f"time require for modulo a number         : {time3-time2}s")



