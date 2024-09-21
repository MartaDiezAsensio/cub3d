# cub3d
Cub3d


NOTA: para obtener el mlx42 codam hay que ejecutar 
git submodule update --init --recursive
desde el root ya que el fichero .gitmodules guarda la ruta y la url del repositorio.

NOTA 19.09
	EL error del vector que se desmadraba era porque si se generaba un rayo en "la mitad de la pantalla" resulta que cameraX era 0.
	Es decir....

	(Camerax = 2* x/w - 1)  donde  x = w/2 => Camerax = 0.
	Al ser 0, y direccion de la camara = 1.0, el rayo tenía rayDiry = direccion.y + cameraX*plane.y => 1.0

	Cuando calculabamos el punto FINAL para pasarselo al DDA , lo calculabamos así:

	final. y = origen.y + raydir.y * INTMAX. 

	cOmo final.y es un int  y raydir.y es 1 * INTMAX... haciamos overflow y final.y se convertía en negativo. (por eso el rayo saltaba hacia arriba cuando todos iban hacia abajo) 

##Resources

- https://hackmd.io/@nszl/H1LXByIE2
- https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
- https://harm-smits.github.io/42docs/projects/cub3d.html
- https://github.com/jareste/Cub3d/blob/main/SRC/main.c





float aprox_angulo;

if (vector.x < 0.00000000001f && vector.x > 0.0f  || vector.x > -0.00000000001f && vector.x < 0.0f)
{
	if (vector.y < 0)
		return(90);
	else
		return (270)
}

m = vector.y / vector.x;
if (m > 0 && m < 1)
{
	if (vector.x < 0)
		return(200);
}	

tangetes.
de 0 a 1 		=> de 0 a 45
de 1 a inf  	=> de 45 a 90
de -inf a -1  	=> de 90 a 135
de -1 a 0  		=> de 135 a 180
de  0 a 1 		=> de 180 a 225
de 1 a inf 		=> de 225 a 270
de -inf a -1 	=> de 270 a 315
de  -1  a 0    	=> de 315 a 0


si tenemos que quedarnos con la X, hacemos destino.x - origen.x => es la distancia "oficial"
Si tenemos que quedarnos con la Y, hcemos destino.y - origen.y => es la distancia "oficial"