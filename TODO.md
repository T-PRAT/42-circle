# INCEPTION

## Se renseigner
- docker compose ?

## Container
- chaque image a le meme nom que le service qui tourne
- chaque service tourne dans un container dédié
- tourne soit sous linux Alpine soit debian buster
- chacun leur dockerfile
### Les diff containers
- NGINX avec TLSv1.2 ou 1.3
- Wordpress + php-fpm(installer et configurer) sans nginx
- MariaDB sans nginx

## docker-compose.yml
- version
- services (en dessous on liste les diff containers)
	-> nom du container
		-> image docker (ou la commande build avec le path du Dockerfile)
		-> volumes (path vers un dossier pour contenir les données persistantes)
		-> restart (politique démarrage du container)
		-> environnement (liste des différentes variable d'environnement)
		-> depends_on (définit des dépendence, service demarre si lui est démarrer)
		-> ports (pour exposer un port)
		->...


# PHILOSOPHER

## Disposition
- Ils sont rangé de 1 a "number_of_phil.." en cercle
- Une fourchette entre chaque philo donc une fourchette par philo et donc la moitié peux manger en meme temps
- Il mange puis dorment puis pense puis si pas de fourchette t_die descend, si fourchette il mange
