# cub3d
Cub3d


NOTA: para obtener el mlx42 codam hay que ejecutar 
git submodule update --init --recursive
desde el root ya que el fichero .gitmodules guarda la ruta y la url del repositorio.

NOTA 1909.
	EL error del vector que se desmadraba era porque se llegaba a rayo de "la mitad" de la pantalla" resulta que cameraX era 0.

	(Camerax = 2* x/w - 1)  donde  x = w/2.
	Al ser 0, y direccion de la camara = 1.0, el rayo tenía rayDiry = direccion.y + cameraX*plane.y => 1.0

	Cuando calculabamos el punto FINAL para pasarselo al DDA , lo calculabamos así:

	final. y = origen.y + raydir.y * INTMAX. 

	cOmo final.y es un int  y raydir.y es 1 * INTMAX... haciamos overflow y final.y se convertía en negativo. (por eso el rayo saltaba hacia arriba cuando todos iban hacia abajo) 

##Resources

- https://hackmd.io/@nszl/H1LXByIE2
- https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
- https://harm-smits.github.io/42docs/projects/cub3d.html
