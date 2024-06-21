# Concorrência e sincronização de threads no padrão POSIX utilizando a linguagem C
<!-- vscode-markdown-toc -->

1. [Objetivo da aula](#Objetivodaaula)
2. [Concorrência e Sincronização](#ConcorrnciaeSincronizao)
  2.1. [Concorrência](#Concorrncia)
    2.1.1. [Principais problemas de concorrência:](#Principaisproblemasdeconcorrncia:)
    2.2. [Sincronização](#Sincronizao)
3. [Questão Proposta](#QuestoProposta)
4. [Objetivo da Aplicação](#ObjetivodaAplicao)
  4.1. [Problema da venda de ingressos](#Problemadavendadeingressos)
5. [Implementação da Aplicação](#ImplementaodaAplicao)
  5.1. [1. Código sem sincronização (para ilustrar os problemas)](#Cdigosemsincronizaoparailustrarosproblemas)
  5.2. [2. Código com sincronização (solução com mutex)](#Cdigocomsincronizaosoluocommutex)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

## 1. <a name='Objetivodaaula'></a>Objetivo da aula

Demonstrar o uso de threads e como elas permitem a execução paralela de tarefas em um programa na linguagem C.

## 2. <a name='ConcorrnciaeSincronizao'></a>Concorrência e Sincronização

### 2.1. <a name='Concorrncia'></a>Concorrência

Concorrência ocorre quando dois ou mais processos ou threads são executados simultaneamente. Em sistemas multiprocessadores, isso pode significar execução real em paralelo; em sistemas de um único processador, significa alternância rápida entre tarefas (time-slicing).

#### 2.1.1. <a name='Principaisproblemasdeconcorrncia:'></a>Principais problemas de concorrência:

- **Condição de corrida (Race Condition)**: Ocorre quando duas ou mais threads podem acessar dados compartilhados e tentar mudar esses dados ao mesmo tempo. A ordem de execução pode afetar o resultado final.
- **Seção Crítica**: Parte do código onde o acesso aos dados compartilhados ocorre. É crucial proteger essas seções para evitar inconsistências.

### 2.2. <a name='Sincronizao'></a>Sincronização

- **Sincronização**: É o uso de mecanismos para controlar a ordem de execução das threads para evitar condições de corrida e garantir a consistência dos dados compartilhados.
- **Mutex (Mutual Exclusion)**: Um dos mecanismos de sincronização mais simples para o entendimento dos alunos. Um mutex é uma variável usada para controlar o acesso a uma seção crítica. Apenas uma thread pode segurar o mutex de cada vez.

## 3. <a name='QuestoProposta'></a>Questão Proposta

Uma banda famosa de rock irá tocar na cidade de São Paulo, e a venda de ingressos para este evento é altamente disputada. Para lidar com a alta demanda, várias bilheterias estão operando simultaneamente, cada uma representada por uma thread em nosso programa. Queremos garantir que o número de ingressos vendidos seja consistente e que não se venda mais ingressos do que os disponíveis.

## 4. <a name='ObjetivodaAplicao'></a>Objetivo da Aplicação

Elaborar uma aplicação em C que simule a venda de ingressos por várias threads. Utilizaremos mecanismos de sincronização do padrão POSIX (pthread) para garantir a integridade dos dados e evitar condições de corrida.

### 4.1. <a name='Problemadavendadeingressos'></a>Problema da venda de ingressos

- **Cenário**: Temos um sistema de venda de ingressos onde vários clientes tentam comprar ingressos ao mesmo tempo.
- **Problema**: Sem sincronização, múltiplos clientes podem acabar comprando o mesmo ingresso devido a condições de corrida.
- **Desafio**: Garantir que apenas o número correto de ingressos seja vendido, evitando overselling.

## 5. <a name='ImplementaodaAplicao'></a>Implementação da Aplicação

### 5.1. <a name='Cdigosemsincronizaoparailustrarosproblemas'></a>1. Código sem sincronização (para ilustrar os problemas)

- Condições de corrida podem ocorrer, resultando em vendas de ingressos inconsistentes.
- Duas threads podem vender o mesmo ingresso simultaneamente.

### 5.2. <a name='Cdigocomsincronizaosoluocommutex'></a>2. Código com sincronização (solução com mutex)

O uso do mutex impede condições de corrida, garantindo que cada ingresso seja vendido apenas uma vez, mesmo quando várias threads tentam vender ingressos simultaneamente.
