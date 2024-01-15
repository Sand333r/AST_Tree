# Calculadora de Expresiones Matemáticas con Árbol de Sintaxis Abstracta (AST)

## Descripción

Este programa en C++ implementa una calculadora de expresiones matemáticas utilizando un Árbol de Sintaxis Abstracta (AST). La calculadora permite ingresar expresiones matemáticas simples que contienen operadores aritméticos básicos (+, -, *, /) y paréntesis para indicar la precedencia de las operaciones.

## Estructura del Proyecto

- **main.cpp:** Contiene la lógica principal del programa, incluyendo la entrada del usuario, la construcción del AST y la evaluación del resultado.
- **expression_tree.h:** Define la estructura del Árbol de Sintaxis Abstracta (AST) y las funciones relacionadas con la creación, liberación y evaluación del árbol.

## Instrucciones de Uso

# Compilación del Programa:

g++ main.cpp -o calculator

# Ejecución del Programa:

./calculator

## Instrucciones de Uso

### Solicitar expresión matemática al usuario:

El programa solicitará al usuario que ingrese una expresión matemática.

### Ingreso de Expresiones:

Puede ingresar expresiones matemáticas que contengan números, operadores (+, -, *, /) y paréntesis para indicar la precedencia de las operaciones.

### Ejemplos válidos:

- `2 + 3 * (4 - 1)`
- `(5 + 2) * 3 / 7`

### Visualización del Resultado:

El programa mostrará el resultado de la expresión ingresada.

## Detalles Técnicos

### Estructura del AST:

- Cada nodo del AST representa un operador (+, -, *, /) o un número.
- Se utilizan dos constructores diferentes en la estructura `ExprNode` para diferenciar entre nodos de operadores y nodos de números.

### Funciones Principales:

- `createExprNode`: Crea un nodo del Árbol de Sintaxis Abstracta (AST).
- `buildExpressionTree`: Construye el AST a partir de una expresión matemática.
- `freeExpressionTree`: Libera la memoria del AST de manera recursiva.
- `evaluateExpressionTree`: Evalúa el resultado de la expresión almacenada en el AST de manera recursiva.
