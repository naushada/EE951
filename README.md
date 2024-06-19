### To Build the docker image.
#### clone the repository inside sw/eMasters
#### change the directory to EE951
#### Run below command at bash shell to build the docker image

sudo docker build --rm -t naushada/ee951:latest $HOME/sw/eMasters/ee951:latest -f Dockerfile

### Running Docker image
docker run naushada/ee951:latest /opt/app/test/EE951_test
