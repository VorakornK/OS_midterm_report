import numpy as np
import os
import subprocess

program_path = "./averagepx"
input_path = "./input.txt"

# n = 500000
n, loop = map(int, input("Enter n, loop: ").split())
err = 0

for _ in range(loop):
    random_num =np.random.randint(0, 256, size=(int(n)), dtype=int) 

    input_data = f"{n}\n" + "\n".join(random_num.astype(str))

    open(input_path, "w").write(input_data)

    result = subprocess.run([program_path], stdin=open(input_path), capture_output=True, text=True)

    if int(result.stdout) != random_num.mean().astype(int):
        err += 1
    # print(result.stdout, end="")
    # print(random_num.mean().astype(int))
    #print(result.stderr)

print(f"Error: {err}/{loop}")
os.remove(input_path)