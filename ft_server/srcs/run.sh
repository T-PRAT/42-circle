#!/bin/bash

if [[ -v INDEXOFF ]];then
sed -i "s/on;/off;/" /etc/nginx/sites-available/site.conf
service nginx stop
fi
service mysql start && service php7.3-fpm start && nginx -g "daemon off;"