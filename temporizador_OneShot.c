#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos pinos dos LEDs e do botão
#define LED_VERMELHO 13
#define LED_VERDE 11
#define LED_AZUL 12
#define BOTAO 5

// Tempo de espera entre os desligamentos (em milissegundos)
#define TEMPO_ESPERA 3000

// Variável para controlar o estado dos LEDs
bool leds_ligados = false;

// Declaração das funções para desligar os LEDs
int64_t desligar_led_verde(alarm_id_t id, void *user_data);
int64_t desligar_led_vermelho(alarm_id_t id, void *user_data);
int64_t desligar_led_azul(alarm_id_t id, void *user_data);

// Função para desligar o LED vermelho e chamar o desligamento do verde
int64_t desligar_led_vermelho(alarm_id_t id, void *user_data)
{
    gpio_put(LED_VERMELHO, false);
    printf("LED vermelho desligado\n");
    add_alarm_in_ms(TEMPO_ESPERA, desligar_led_verde, NULL, false);
    return 0;
}

// Função para desligar o LED verde e liberar o controle dos LEDs
int64_t desligar_led_verde(alarm_id_t id, void *user_data)
{
    gpio_put(LED_VERDE, false);
    printf("LED verde desligado\n");
    leds_ligados = false; // Permite que os LEDs sejam acionados novamente
    return 0;
}

// Função para desligar o LED azul e iniciar o ciclo de desligamento dos outros LEDs
int64_t desligar_led_azul(alarm_id_t id, void *user_data)
{
    gpio_put(LED_AZUL, false);
    printf("LED azul desligado\n");
    add_alarm_in_ms(TEMPO_ESPERA, desligar_led_vermelho, NULL, false);
    return 0;
}

// Configuração inicial dos pinos GPIO
void configurar_gpio()
{
    // Inicializa os pinos dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    // Inicializa o botão com pull-up ativado
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
}

// Função principal
int main()
{
    // Inicializa a comunicação serial
    stdio_init_all();

    // Configura os pinos GPIO
    configurar_gpio();

    // Loop infinito para verificar o botão
    while (true)
    {
        sleep_ms(100); // Evita polling excessivo

        // Verifica se o botão foi pressionado e os LEDs estão disponíveis para serem acionados
        if (gpio_get(BOTAO) == 0 && !leds_ligados)
        {
            // Liga todos os LEDs
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_AZUL, 1);
            printf("LEDs ligados\n");

            // Bloqueia novos acionamentos até que os LEDs sejam desligados
            leds_ligados = true;

            // Inicia o ciclo de desligamento
            add_alarm_in_ms(TEMPO_ESPERA, desligar_led_azul, NULL, false);
        }
    }
    
    return 0;
}
