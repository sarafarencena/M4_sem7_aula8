# Módulo 4 - Ponderada Semana 7

## Mapa de Calor calculando dBm de sinal WiFi

Essa atividade implementa um sistema de monitoramento da intensidade do sinal WiFi utilizando um ESP32 DevKit conectado à rede Inteli.Iot. O dispositivo realiza medições contínuas da potência do sinal de radiofrequência em dBm através da função WiFi.RSSI() e publica os dados a cada 5 segundos para a plataforma Adafruit IO via protocolo MQTT. Os valores coletados são visualizados em tempo real através de um gráfico de linha (tempo x dBm) configurado na dashboard online, permitindo análise temporal das variações de sinal.​

O objetivo principal foi demonstrar experimentalmente o efeito da Gaiola de Faraday em um ambiente real, utilizando o elevador do Inteli como estrutura metálica bloqueadora de sinais eletromagnéticos. Os testes realizados evidenciaram quedas abruptas nos valores de dBm ao entrar no elevador e recuperação imediata do sinal ao sair, registrando o bloqueio temporário de conectividade WiFi no gráfico da plataforma. O projeto integra conceitos de sistemas embarcados, comunicação wireless, protocolo MQTT e visualização de dados em IoT.

-Acesse [aqui](https://drive.google.com/file/d/1V3zlIbADeuaBiAnsx4wFrIuFE9sPyv40/view?usp=sharing) o gráfico do resultado obtido com o experimento.

- Acesse [aqui](https://youtu.be/06fsq_pSLd8?si=F--tdfcvRl5JN6TM) o vídeo de demonstração do experimento.
