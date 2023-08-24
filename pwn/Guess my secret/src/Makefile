image:
	docker build -t guess .

chall:
	gcc -fstack-protector -o chall guess.c 

deploy:
	docker run -d -p 127.0.0.1:5003:1337 -it guess
