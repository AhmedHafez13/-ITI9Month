# Docker - Lab 1

## Task 1

### 1. Run container from any image

```sh
sudo docker container run --name test-container -it ubuntu
```

![](screenshots/screenshot_1.png)

### 2. Check the container status

```sh
sudo docker container ls -a
```

![](screenshots/screenshot_2.png)

### 3. Start the stopped container

```sh
sudo docker container start test-container
```

![](screenshots/screenshot_3.png)

### 4. Remove the container

```sh
sudo docker container run --name new-container -it ubuntu

sudo docker container rm new-container
```

![](screenshots/screenshot_4.png)

### 5. Remove the image

```sh
sudo docker images
sudo docker pull ubuntu:18.04
sudo docker image rm ubuntu:18.04
sudo docker image -ls
```

![](screenshots/screenshot_5.png)

---

## Task 2

### 1. Run container centos or ubuntu in an interactive mode

### 2.Run the following command in the container “echo docker ”

### 3. Open a bash shell in the container and touch a file named hello-docker

```sh
sudo docker container run --name new-container -it ubuntu
```

![](screenshots/screenshot_6.png)

### 4. Stop the container and remove it

```sh
sudo docker container rm new-container
```

![](screenshots/screenshot_7.png)

### 5. Remove all stopped containers

```sh
sudo docker container prune
sudo docker container ls -a
```

## ![](screenshots/screenshot_8.png)

---

## Task 3

### 1. Run a container httpd with name apache

### 2. Remove the container

```sh
sudo docker container run --name test-apache -id httpd
sudo docker stop test-apache
sudo docker container rm test-apache
```

![](screenshots/screenshot_9.png)

### 3. Run a new container with the following:

- Map port 80 to port 9898 on your host machine
- Access the html files from your browser

```sh
sudo docker run -d -p 127.0.0.1:9898:80 --name httpd-container -it httpd
```

![](screenshots/screenshot_11.png)
![](screenshots/screenshot_12.png)

---

## Task 4

### 1. Run the image httpd again.

### 2. Add html static files to the container and make surethey are accessible

```sh
sudo docker start httpd-container
sudo docker container exec -it httpd-container bash

cd /usr/local/apache2
git clone https://github.com/ShaifArfan one-page-website-html-css-project.git htdocs
```

![](screenshots/screenshot_13.png)
![](screenshots/screenshot_14.png)

### 3. Commit the container with image name IMAGE_NAME

```sh
sudo docker commit 538a5548392a ahmedhafez13 httpd-container
sudo docker images
```

![](screenshots/screenshot_15.png)
![](screenshots/screenshot_16.png)

---

## Task 5

### Deploy a MySQL database called app-database. Use the mysql latest image, and use the -e flag to set MYSQL_ROOT_PASSWORD to P4sSw0rd0!. The container should run in the background.

```sh
sudo docker container run --name mysql-container -p 127.0.0.1:3306:3306 -e MYSQL_ROOT_PASSWORD=P4sSw0rd0! -id mysql

sudo docker container ls -a
```

![](screenshots/screenshot_17.png)
![](screenshots/screenshot_18.png)
