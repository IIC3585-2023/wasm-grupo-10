# Grupo 10

- Rafaela Kara
- Cristóbal Muñoz
- Flavio Tarsetti

## Cómo probar

- Instalar y activar Emscritpen
- Si se quiere modificar el archivo `main.cpp`, correr `emcc -O3 codecpp/main.cpp -o codecpp/main.js -s EXPORTED_FUNCTIONS=_cppSolve,_malloc,_free -s EXTRA_EXPORTED_RUNTIME_METHODS=ccall`
- Correr `python -m http.server`
- Abrir `localhost:8000/main.html`
