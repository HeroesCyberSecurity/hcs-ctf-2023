image:
	docker build -t itsmart .

chall:
	gcc -fstack-protector -o chall itsmart.c 

deploy:
	docker run -d -p 127.0.0.1:5005:1337 -it itsmart
