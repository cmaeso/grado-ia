import os
import sys
from rdflib import Graph

def leer_fichero(file_path):
    try:
        # Abrir el archivo en modo lectura
        with open(file_path, 'r', encoding='utf-8') as file:
            # Leer el contenido completo del archivo
            contenido = file.read()
        return contenido
    except FileNotFoundError:
        return f"Error: El archivo '{file_path}' no fue encontrado."
    except Exception as e:
        return f"Error: {e}"


# Verificar si se recibieron 2 argumentos (además del nombre del script)
if len(sys.argv) != 3:
    print("\nError: Debes proporcionar dos parámetros:")
    print("\t 1. El primer archivo contiene la ontología con la información.")
    print("\t 2. El segundo archivo contiene la sentencia sparql.")
    print("\nUso: python script.py <archivo1> <archivo2>:")
    print("\tEjemplo: python3 procesarSparql.py  examplePersonaCompañia.ttl querySparql.txt")
    sys.exit(1)  # Salida con error

# Obtener los nombres de los archivos de los argumentos
ontology_file = sys.argv[1]
archivo2 = sys.argv[2]

# Verificar si los archivos existen en la misma carpeta del script
if not os.path.isfile(ontology_file):
    print(f"Error: El archivo '{ontology_file}' no existe en la carpeta.")
    sys.exit(1)

if not os.path.isfile(archivo2):
    print(f"Error: El archivo '{archivo2}' no existe en la carpeta.")
    sys.exit(1)

g = Graph()
g.parse(ontology_file, format="ttl")  # Cambia el formato a 'ttl' para Turtle

# Consulta SPARQL para obtener la lista de personas
sparql_query = leer_fichero(archivo2)

# Ejecutar la consulta SPARQL
results = g.query(sparql_query)

# Imprimir los resultados
print("\nCampos:", end="")
for var in results.vars:
    print(f" [{var}] " , end="")

print()
print("\t------------------------------------------------------------------------\n\nRegistros:\n")
for row in results:
    print(f"\t", end="" )
    
    for element in row:
        if (element is not None):        
            print(f"[{element}] ", end="" )
    print("")

print()
