FROM gcc:latest

RUN apt-get update
RUN apt-get install default-jdk -y default-jre -y cmake -y docker.io -y docker -y

ENV DOCKER_HOST=tcp://172.18.0.2:

WORKDIR /home/jenkins