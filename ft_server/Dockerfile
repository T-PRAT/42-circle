#image
FROM debian:buster

#install
RUN apt-get update && \
	apt-get install -y nginx wget mariadb-server php7.3-fpm php7.3-mysql&& \
	cd /tmp && wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz && \
	wget https://wordpress.org/latest.tar.gz
RUN cd /tmp && tar xf latest.tar.gz && tar xf phpMyAdmin-4.9.5-english.tar.gz && \
	rm latest.tar.gz phpMyAdmin-4.9.5-english.tar.gz && \
	mv /tmp/wordpress/ /var/www/html/wordpress && mv /tmp/phpMyAdmin-4.9.5-english /var/www//html/phpmyadmin && \
	chown -R www-data:www-data /var/www/html/wordpress/ && \
	rm -f /var/www/html/index.nginx-debian.html

#SSL
RUN mkdir /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=FR/ST=Occitanie/L=Toulouse/O=42/CN=null' -keyout /etc/nginx/ssl/site.key -out /etc/nginx/ssl/site.crt

#nginx conf
COPY srcs/site.conf /etc/nginx/sites-available/site.conf
RUN ln -s /etc/nginx/sites-available/site.conf /etc/nginx/sites-enabled/site.conf && service nginx reload

#mySQL conf
RUN service mysql start && \
	mysql -u root -p"root" -e "CREATE USER 'username'@'localhost' IDENTIFIED BY 'password'" && \
	mysql -u root -p"root" -e "CREATE DATABASE wordpress CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_520_ci;" && \
	mysql -u root -p"root" -e "GRANT ALL PRIVILEGES ON * . * TO 'username'@'localhost';" && \
	mysql -u root -p"root" -e "FLUSH PRIVILEGES"

#copy run script
COPY srcs/run.sh /
RUN chmod +x /run.sh

#open ports
EXPOSE 80
EXPOSE 443

#run nginx
CMD '/run.sh'