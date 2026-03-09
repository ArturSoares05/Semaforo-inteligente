# 🚦 Semáforo Inteligente para Pedestres com Arduino

## 📌 Descrição

Este projeto consiste no desenvolvimento de um protótipo de **semáforo inteligente para pedestres**, utilizando um Arduino como microcontrolador principal. O sistema simula o funcionamento de um cruzamento urbano, permitindo que o pedestre solicite a travessia por meio de um botão.

Diferente de um semáforo básico, o projeto incorpora recursos adicionais que melhoram a comunicação com o usuário, como **contagem visual de tempo por meio de uma barra de LEDs** e **sinalização sonora utilizando um buzzer**, tornando o sistema mais intuitivo e acessível.

O sistema também integra o controle do **semafóro de veículos**, garantindo que a mudança de estado ocorra de forma segura e organizada.

---

## ⚙️ Componentes Utilizados

* Arduino (Uno ou compatível)
* LEDs para sinalização de veículos
* LEDs para sinalização de pedestres
* Barra de **10 LEDs** para indicação de tempo de travessia
* 2 registradores de deslocamento (74HC595)
* Buzzer
* Botão para solicitação de travessia
* Resistores
* Protoboard
* Jumpers

---

## 🧠 Funcionamento do Sistema

O funcionamento do sistema ocorre da seguinte forma:

1. O semáforo inicia com **veículos em verde** e **pedestres em vermelho**.
2. Quando o pedestre pressiona o botão de travessia, o sistema aguarda um tempo mínimo de segurança.
3. O semáforo de veículos passa pela sequência:

   * Verde → Amarelo → Vermelho.
4. Após a parada dos veículos, o **sinal verde para pedestres é liberado**.
5. Durante a travessia, uma **barra de 10 LEDs** indica visualmente o tempo restante, apagando gradualmente conforme o tempo passa.
6. Um **buzzer emite sinais sonoros**, indicando o início da travessia e alertando quando o tempo está terminando.
7. Ao final do tempo, o sistema retorna ao estado inicial, liberando novamente o tráfego de veículos.

---

## ✨ Diferenciais do Projeto

Este projeto apresenta alguns recursos adicionais em relação a um semáforo simples:

* ✔ Solicitação de travessia por botão
* ✔ **Indicador visual de tempo restante com barra de LEDs**
* ✔ **Sinalização sonora para acessibilidade**
* ✔ Integração completa entre semáforo de pedestres e veículos
* ✔ Uso de **registradores de deslocamento (74HC595)** para expansão de saídas do microcontrolador

Esses elementos tornam o sistema mais informativo e próximo de soluções utilizadas em sistemas reais de controle de tráfego.

---

## 🧩 Conceitos Aplicados

Durante o desenvolvimento foram aplicados conceitos importantes de:

* Eletrônica digital
* Sistemas embarcados
* Expansão de portas de I/O
* Manipulação de bits
* Integração entre hardware e software

---

## 📷 Demonstração do Projeto

Imagem do Circuito no Simulador

<img width="1276" height="726" alt="image" src="https://github.com/user-attachments/assets/e24a23ef-6278-47ec-b501-72ef32445b73" />

## 📁 Estrutura do Repositório

```
semaforo-pedestre/
│
├── codigo/
│   └── semaforo.ino
│
├── imagens/
│   └── circuito.jpg
│
└── README.md
```

---

## 👨‍💻 Autor

Projeto desenvolvido por Arthur de Paula Rosendo, Artur Soares, Gabriel Kenji Iwasaki e Vitor Ferreira como atividade acadêmica na disciplina de Sistemas Embarcados.
