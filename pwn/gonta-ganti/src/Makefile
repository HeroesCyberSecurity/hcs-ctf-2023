image:
	docker build -t gonta-ganti .

chall:
	gcc -fno-stack-protector -o chall gonta-ganti.c 

deploy:
	docker run -d -p 127.0.0.1:5002:1337 -it gonta-ganti
