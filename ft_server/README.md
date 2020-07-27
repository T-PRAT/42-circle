# FT_SERVER

## Build
> docker build . --rm -t ft_server/latest

## Run
- autoindex on :
> docker run -it -p 80:80 -p 443:443 ft_server/latest

- autoindex off :
> docker run -it -p 80:80 -p 443:443 -eINDEXOFF= ft_server/latest
