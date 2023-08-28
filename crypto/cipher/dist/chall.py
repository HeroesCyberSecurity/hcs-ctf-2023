import random
import string

def deriveKey(string, key):
	key = list(key)
	if len(string) == len(key):
		return(key)
	else:
		for i in range(len(string) -len(key)):
			key.append(key[i % len(key)])
	return "".join(key)
	
def encrypt(string, key):
	cipher_text = []
	for i in range(len(string)):
		x = (ord(string[i]) ^ ord(key[i]) + ord(key[i])) % 256
		x += 256
		cipher_text.append(chr(x))
	return "".join(cipher_text)

	
if __name__ == "__main__":
	plaintext = "HCS{modified_vigenere_cipher}"
	key = [random.choice(string.ascii_uppercase) for _ in range(4)]
	key = deriveKey(plaintext, key)
	ct = encrypt(plaintext, key)
	out = open("ct.bin", "w")
	out.write(ct)