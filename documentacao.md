# Mapa de Calor calculando dBm de sinal WiFi

Essa atividade implementa um sistema de monitoramento de intensidade de sinal WiFi baseado em ESP32, com envio contínuo dos valores de dBm para a plataforma Adafruit IO via MQTT. O objetivo é analisar cenários de variação de sinal, especialmente o efeito de bloqueio em ambientes com estrutura metálica (Gaiola de Faraday), como o elevador, e registrar os dados em dashboard online em tempo real.


## 1. Configuração do Dashboard na Adafruit IO

- Acesse sua conta em [io.adafruit.com](https://io.adafruit.com) e crie um novo **Feed** chamado `wifi-signal-db`.
- No menu “Dashboards”, clique em **Create a Dashboard** e dê um nome e descrição.
- Acesse o dashboard e adicione um **Line Chart** (gráfico de linha) associado ao feed criado.
- Configure o gráfico para exibir o histórico das últimas 1 a 2 horas, label de eixo X como “Tempo” e eixo Y como “dBm”. Defina o mínimo do eixo Y como -100 e o máximo como -20 para melhor visualização das variações de sinal.
- Salve e teste o bloco. O gráfico atualizará automaticamente a cada novo valor publicado.
- [Acesse aqui o gráfico do resultado obtido com o experimento.](https://drive.google.com/file/d/1V3zlIbADeuaBiAnsx4wFrIuFE9sPyv40/view?usp=sharing)


## 2. Código para o Arduino IDE

O código utiliza as bibliotecas `WiFi.h`, `Adafruit_MQTT.h` e `Adafruit_MQTT_Client.h` para realizar a conexão com a rede, coleta do RSSI (dBm), e publicação via MQTT para a Adafruit IO a cada 5 segundos. Para o experimento, todas as credenciais necessárias (SSID, senha, user, AIO Key) foram configuradas para o ambiente esperado. Entretanto, por questões de segurança, esses dados foram preservados para ser possível o upload do código no GitHub.


## 3. Montagem do Dispositivo Físico

- **Componentes necessários**:
  - 1x ESP32
  - 1x Cabo USB (tipo micro USB)
  - 1x Antena 2.4Ghz 3dBi Wifi RP-SMA IPEX MT7681
- **Montagem**:
  - Conecte a antena ao ESP32 e então ao computador usando o cabo USB, que fornece alimentação e comunicação.


## 4. Execução do Experimento e Registro do Bloqueio de Sinal

- Com o dispositivo conectado e código rodando, observe no serial monitor da IDE os valores publicados.
- Deixe a dashboard do Adafruit IO aberta para acompanhar o gráfico em tempo real.
- Circule por diferentes ambientes para capturar distintos níveis de sinal.
- No momento do teste da Gaiola de Faraday, entre no elevador do Inteli com o ESP32 alimentado (pode ser via notebook ou power bank).
- Permaneça pelo menos 5 segundos dentro do elevador, observando a queda brusca ou perda dos valores no gráfico, indicando o bloqueio do sinal WiFi.
- Saia do elevador e registre a rápida recuperação dos valores de dBm.
- [Acesse aqui o vídeo de demonstração do experimento.](https://youtu.be/06fsq_pSLd8?si=F--tdfcvRl5JN6TM)


## 5. Considerações Finais

- O experimento evidencia de forma prática conceitos de radiofrequência, efeito da gaiola de Faraday, comunicação MQTT em IoT e visualização remota de dados.
- O código e a plataforma permitem reconfigurações rápidas para outras métricas IoT, bastando atualizar o feed e o payload MQTT.