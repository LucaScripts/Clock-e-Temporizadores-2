![image](https://github.com/user-attachments/assets/24d0183a-f6e3-40de-991c-a06dcdf42a55)# 🚦 Controle de LEDs com Raspberry Pi Pico
📌 Autor: Lucas Dias

📆 Data: 31/01/2025

Este projeto implementa o controle de três LEDs (vermelho, verde e azul) com o **Raspberry Pi Pico**, onde os LEDs são ativados e desligados sequencialmente após o pressionamento de um botão. A lógica utiliza **temporizadores** para gerenciar os tempos de desligamento dos LEDs.

---

## 📌 **Características**
✅ Controle de LEDs sequencial (vermelho → verde → azul).  
✅ Uso de temporizadores para desligamento automático dos LEDs.  
✅ Mensagens de depuração exibidas via **serial**.  
✅ Código modular e bem documentado.

---

## 🛠 **Materiais Necessários**
🔹 1x **Raspberry Pi Pico**  
🔹 1x **LED Vermelho**  
🔹 1x **LED Verde**  
🔹 1x **LED Azul**  
🔹 1x **Botão**  
🔹 3x **Resistores de 330Ω**  
🔹 Fios jumper e protoboard  

---

## 🏗 **Esquema de Ligação**
| Componente   | Pino do Raspberry Pi Pico |
|--------------|---------------------------|
| LED Vermelho | GPIO 13                   |
| LED Verde    | GPIO 11                   |
| LED Azul     | GPIO 12                   |
| Botão        | GPIO 5                    |

**⚠️ OBS:** O lado positivo do LED deve ser conectado ao GPIO correspondente e o negativo ao GND através de um **resistor de 330Ω**.

---

## 📜 **Instalação e Execução**

### **1️⃣ Configurar o ambiente**
Certifique-se de ter o **Pico SDK** instalado e configurado no seu sistema.  

Se ainda não configurou, siga as instruções oficiais:  
🔗 [Guia Oficial do Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

## 📥 Clonando o Repositório e  Compilando e Enviando para o Raspberry Pi Pico

Para baixar o código e começar a trabalhar com ele clonar o repositório e carregar o código na placa siga os passos abaixo:

![Clonando o Repositório](https://github.com/LucaScripts/Clock-e-Temporizadores/blob/main/docs/Bem-vindo%20-%20Visual%20Studio%20Code%202025-01-31%2018-49-32.gif?raw=true)

---

Após a compilação, copie o arquivo `.uf2` gerado para o Raspberry Pi Pico (modo bootloader ativado).


## 🧪 Testando na Placa BitDogLab

Aqui está o teste do semáforo rodando na **Placa BitDogLab**:

![Testando na BitDogLab](https://github.com/LucaScripts/Clock-e-Temporizadores-2/blob/main/docs/WhatsApp%20Video%202025-01-31%20at%2019.28.55.gif?raw=true)

---

## 🎯 **Funcionamento**
- O código inicia com **todos os LEDs ligados**.  
- A cada **3 segundos**, o LED azul é desligado, seguido pelo LED vermelho e, por último, o LED verde.  
- O ciclo se repete até que o botão seja pressionado novamente para reiniciar o processo.  
- Durante o ciclo, o controle de LEDs é bloqueado para evitar acionamentos repetidos enquanto o ciclo está em andamento.

---

## 🚦 Demonstração da Simulação

Abaixo está uma prévia da simulação do semáforo no **Wokwi**:

![Simulação do Semáforo no Wokwi](https://github.com/LucaScripts/Clock-e-Temporizadores-2/blob/main/docs/Clock-e-Temporizadores-2%20-%20Visual%20Studio%20Code%202025-01-31%2019-22-00.gif?raw=true)

---

## 📌 **Melhorias Futuras**
- 🚀 Adição de novos **modos de controle** para os LEDs (exemplo: modo piscante, sequência aleatória).  
- 🛠 Implementação de um **display de status** para indicar o estado atual dos LEDs.  
- 📡 Adição de controle remoto via **Wi-Fi** ou **Bluetooth**.
