from base64 import b64encode

key = b'ITSU'

ct = open("output", "rb").read()
print(b64encode(ct))
pt = []
for i in range(len(ct)):
    pt.append(chr(ct[i] ^ key[i % len(key)]))
    
print(''.join(pt))