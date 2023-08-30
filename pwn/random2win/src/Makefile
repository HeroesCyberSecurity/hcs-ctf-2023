image:
	docker build -t random2win .

chall:
	gcc -no-pie -fno-stack-protector -o chall random2win.c 

deploy:
	docker run -d -p 127.0.0.1:5004:1337 -it random2win
