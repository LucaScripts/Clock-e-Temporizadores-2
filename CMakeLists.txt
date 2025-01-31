# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Arquivo CMake gerado para o projeto Pico

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializa o pico_sdk a partir da localização instalada
# (nota: isso pode vir do ambiente, cache do CMake, etc.)

# == NÃO EDITE AS LINHAS ABAIXO para que a extensão do VS Code funcione corretamente com o Raspberry Pi Pico ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Tipo de Placa")

# Inclui o SDK do Raspberry Pi Pico (deve ser antes de 'project')
include(pico_sdk_import.cmake)

# Define o projeto com os tipos de linguagens
project(temporizador_OneShot C CXX ASM)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()

# Adiciona o executável. O nome padrão é o nome do projeto, versão 0.1
add_executable(temporizador_OneShot temporizador_OneShot.c)

# Define o nome e a versão do programa
pico_set_program_name(temporizador_OneShot "temporizador_OneShot")
pico_set_program_version(temporizador_OneShot "0.1")

# Modifique as linhas abaixo para habilitar/desabilitar a saída via UART/USB
pico_enable_stdio_uart(temporizador_OneShot 1)
pico_enable_stdio_usb(temporizador_OneShot 1)

# Adiciona a biblioteca padrão ao build
target_link_libraries(temporizador_OneShot
        pico_stdlib)

# Adiciona os arquivos de cabeçalho padrão ao build
target_include_directories(temporizador_OneShot PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Adiciona bibliotecas adicionais requisitadas pelo usuário
target_link_libraries(temporizador_OneShot 
        hardware_timer
)

# Adiciona saídas extras para o projeto
pico_add_extra_outputs(temporizador_OneShot)
