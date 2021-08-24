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
- rl_, add_history : fonctions qui modifie le contenue de la ligne renvoyer par readline
- fork : duplique le process actuel et le process créé est appelé child process
- wait : attend jusqu'a un changement d'état du processus passer en param
- getcwd : retourne une string du pathname du processus appelant
- chdir : remplace le répertoire courant par celui indiqué dans le chemin path
- (l, f)stat : ces fonctions retourne des infos sur un fichier
- unlink : supprime un nom du filesystem, si le nom est un fichier, le fichier est supprimer
- execve : execute le programme pointer par filename
- dup : alloue un nouveau fd
- pipe : crée un pipe, un flux de données unidirectionel vers un autre process
- strerror : retourne un pointeur vers une str qui decrit le code erreur passer
- perror : produit un message d'erreur qui decrit l erreur rencontrer pendant le dernier appel systeme
- isatty : test si le fd correspond a celui d'un terminal
- ttyname : retourne le nom du terminal qui est ouvert sur le fd
- ttyslot : retourne l'index de l'entrée de l'user dans un fichier
- getenv : recherche dans la liste des variables d'env la variable name et renvoie sa valeur

## Etapes
### 1- Parsing
- tokenisation

