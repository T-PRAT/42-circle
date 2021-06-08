#image
FROM debian:buster

#install
RUN apt-get update && apt-get install -y nginx

#copy nginx.conf
COPY nginx.conf /etc/nginx

#open ports
EXPOSE 80

#run nginx
CMD ["nginx", "-g", "daemon off;"]
