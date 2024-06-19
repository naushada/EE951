### To Build the docker image.
#### clone the repository inside sw/eMasters
#### change the directory to docker
#### Run below command at bash shell to build the docker image

sudo docker build --rm -t naushada/ee951:latest $HOME/sw/eMasters/EE951 -f Dockerfile

### Running Docker image test case
docker run naushada/ee951:latest /opt/app/test/EE951_test

### Running Docker image
docker run naushada/ee951:latest /opt/app/test/EE951

### Running in interactive fashion
docker run -h mahmed -it naushada/ee951:latest /bin/bash

