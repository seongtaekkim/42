NAME	= inception
all	: $(NAME)
$(NAME)	:
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb ${HOME}/data/site ${HOME}/data/monitor
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 seongtki.42.fr" >> /etc/hosts
	sudo docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

clean	:
	sudo docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans

fclean	: clean
	sudo rm -rf ${HOME}/data
	sudo rm -f .setup
	sudo docker system prune --volumes --all --force
	sudo docker network prune --force
	sudo docker volume prune --force

re	: fclean all

restart	:
	sudo docker-compose -f srcs/docker-compose.yml restart

.PHONY	: all clean fclean restart 
