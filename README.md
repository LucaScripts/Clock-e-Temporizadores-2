# 🚦 Controle de LEDs com Raspberry Pi Pico
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

### **2️⃣ Clonar o repositório**
```bash
git clone https://github.com/LucaScripts/Clock-e-Temporizadores-2.git
cd Clock-e-Temporizadores-2
```

### **3️⃣ Compilar e enviar o código para o Raspberry Pi Pico**
No ambiente **VS Code** com o **Pico SDK** configurado:  
```bash
mkdir build
cd build
cmake ..
make
```
Após a compilação, copie o arquivo `.uf2` gerado para o Raspberry Pi Pico (modo bootloader ativado).

---

## 🎯 **Funcionamento**
- O código inicia com **todos os LEDs ligados**.  
- A cada **3 segundos**, o LED azul é desligado, seguido pelo LED vermelho e, por último, o LED verde.  
- O ciclo se repete até que o botão seja pressionado novamente para reiniciar o processo.  
- Durante o ciclo, o controle de LEDs é bloqueado para evitar acionamentos repetidos enquanto o ciclo está em andamento.

---

## 📌 **Melhorias Futuras**
- 🚀 Adição de novos **modos de controle** para os LEDs (exemplo: modo piscante, sequência aleatória).  
- 🛠 Implementação de um **display de status** para indicar o estado atual dos LEDs.  
- 📡 Adição de controle remoto via **Wi-Fi** ou **Bluetooth**.
