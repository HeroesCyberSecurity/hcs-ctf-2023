image:
	docker build -t koecing .

chall:
	gcc -no-pie -fno-stack-protector -z execstack -z norelro -o chall koecing.c 

deploy:
	docker run -d -p 127.0.0.1:5000:1337 -it koecing