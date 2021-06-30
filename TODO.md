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


# MINISHELL

## Role des fonctions
- readline : lit une ligne du prompt et renvoie la l'adresse de la ligne malloquer
-  rl_ : fonctions qui modifie le contenue de la ligne renvoyer par readline

# Philo

## test

- Check how the death of a philosopher is checked and if there is a mutex to protect that a philosopher dies and start eating at the same time.
- Test with 1 800 200 200, the philosopher should not eat and should die!
- Test with 5 800 200 200, no one should die!
- Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
- Test with 4 410 200 200, no one should die!
- Test with 4 310 200 100, a philosopher should die!
- Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).
- Test with your values to check all the rules. Check if a philosopher dies at the right time if they don't steal forks, etc.

