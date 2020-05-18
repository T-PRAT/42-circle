#image
FROM debian:buster

#install
RUN apt-get update
RUN apt-get install -y nginx

#open ports
EXPOSE 80

#run nginx
CMD ["nginx", "-g", "daemon off;"]
