file = open("output", "rb").read()
for key in range(256):
    tmp = []
    for f in file:
        tmp.append(chr(f ^ key))
    print(f'{key=}, {"".join(tmp)}')