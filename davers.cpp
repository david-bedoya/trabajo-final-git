
# cook your dish here
cantidad_instrucciones = int(input())
 
diccionarios_carpetas={}
diccionarios_carpetas["Mark"]={}
 
ubicacion_actual="/Mark"
 
def imprimir(directorio_padre, directorios, nivel):
    print(directorio_padre+":")
    for directorio_hijo in directorios:
        print("--"*(nivel+1),end="")
        imprimir(directorio_hijo, directorios[directorio_hijo], nivel+1)
def insertar(ubicacion, nueva_carpeta):
    navegacion = diccionarios_carpetas
    directorios= ubicacion.split("/")[1:]
	
    for directorio in directorios:
        navegacion = navegacion[directorio]
    navegacion [nueva_carpeta]={}
      
for _ in range(cantidad_instrucciones):
    instruccion, argumento = input().split(" ")
		
    if instruccion == "cd":
				
        if argumento == "..":
            ubicacion_actual="/".join(ubicacion_actual.split("/")[:-1])
        else:
            ubicacion_actual=ubicacion_actual+"/"+argumento
    else:
        insertar(ubicacion_actual,argumento)
imprimir("Mark",diccionarios_carpetas["Mark"],0)
