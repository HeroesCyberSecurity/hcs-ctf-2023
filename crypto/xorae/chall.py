FLAG = B'HCS{????????????????}'
key = ???

file = open("output", "wb")
for f in FLAG:
    file.write(chr(f ^ key).encode())